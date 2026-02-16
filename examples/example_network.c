/**
 * @file      example_network.c
 * @brief     网络模块示例代码源文件
 * @author    huenrong (sgyhy1028@outlook.com)
 * @date      2026-02-16 16:25:16
 *
 * @copyright Copyright (c) 2026 huenrong
 *
 */

#include <stdio.h>
#include <string.h>

#include "gm_network.h"

/**
 * @brief 程序入口
 *
 * @param[in] argc: 参数个数
 * @param[in] argv: 参数列表
 *
 * @return 成功: 0
 * @return 失败: 其它
 */
int main(int argc, char *argv[])
{
    char ifname[32] = "eth0";
    if (argc < 2)
    {
        printf("use default ifname: %s\n", ifname);
    }
    else
    {
        strncpy(ifname, argv[1], sizeof(ifname) - 1);
        ifname[sizeof(ifname) - 1] = '\0';
        printf("use ifname: %s\n", ifname);
    }

    char mac_addr[GM_NETWORK_MAC_ADDRSTRLEN] = "";
    int ret = gm_network_get_mac_addr(ifname, mac_addr, sizeof(mac_addr));
    if (ret != 0)
    {
        printf("get %s mac addr failed. ret: %d\n", ifname, ret);
    }
    else
    {
        printf("%s mac addr: %s\n", ifname, mac_addr);
    }

    gm_ipv4_info_t gm_ipv4_info[10] = {0};
    ret = gm_network_get_ipv4_info(ifname, gm_ipv4_info, sizeof(gm_ipv4_info) / sizeof(gm_ipv4_info[0]));
    if (ret > 0)
    {
        printf("%s ipv4 info:\n", ifname);
        for (int i = 0; i < ret; i++)
        {
            printf("\t index: %d, ip: %s, prefix: %d\n", i, gm_ipv4_info[i].ip, gm_ipv4_info[i].prefix);
        }
    }
    else if (ret == 0)
    {
        printf("%s has no ipv4 info\n", ifname);
    }
    else
    {
        printf("get %s ipv4 info failed. ret: %d\n", ifname, ret);
    }

    char ipv4_gateway[INET_ADDRSTRLEN] = "";
    ret = gm_network_get_ipv4_default_gateway(ifname, ipv4_gateway, sizeof(ipv4_gateway));
    if (ret > 0)
    {
        printf("%s ipv4 default gateway: %s\n", ifname, ipv4_gateway);
    }
    else if (ret == 0)
    {
        printf("%s has no ipv4 default gateway\n", ifname);
    }
    else
    {
        printf("get %s ipv4 default gateway failed. ret: %d\n", ifname, ret);
    }

    gm_ipv6_info_t gm_ipv6_info[10] = {0};
    ret = gm_network_get_ipv6_info(ifname, gm_ipv6_info, sizeof(gm_ipv6_info) / sizeof(gm_ipv6_info[0]));
    if (ret > 0)
    {
        printf("%s ipv6 info:\n", ifname);
        for (int i = 0; i < ret; i++)
        {
            printf("\t index: %d, ip: %s, prefix: %d\n", i, gm_ipv6_info[i].ip, gm_ipv6_info[i].prefix);
        }
    }
    else if (ret == 0)
    {
        printf("%s has no ipv6 info\n", ifname);
    }
    else
    {
        printf("get %s ipv6 info failed. ret: %d\n", ifname, ret);
    }

    char ipv6_gateway[INET6_ADDRSTRLEN] = "";
    ret = gm_network_get_ipv6_default_gateway(ifname, ipv6_gateway, sizeof(ipv6_gateway));
    if (ret > 0)
    {
        printf("%s ipv6 default gateway: %s\n", ifname, ipv6_gateway);
    }
    else if (ret == 0)
    {
        printf("%s has no ipv6 default gateway\n", ifname);
    }
    else
    {
        printf("get %s ipv6 default gateway failed. ret: %d\n", ifname, ret);
    }

    char ipv4_netmask[INET_ADDRSTRLEN] = "255.255.0.0";
    uint8_t ipv4_prefix = 0;
    ret = gm_network_ipv4_netmask_to_prefix(ipv4_netmask, &ipv4_prefix);
    if (ret != 0)
    {
        printf("ipv4 netmask to prefix failed. ret: %d, netmask: %s\n", ret, ipv4_netmask);
    }
    else
    {
        printf("ipv4 netmask to prefix success. netmask: %s, prefix: %d\n", ipv4_netmask, ipv4_prefix);
    }

    ipv4_prefix = 24;
    memset(ipv4_netmask, 0, sizeof(ipv4_netmask));
    ret = gm_network_ipv4_prefix_to_netmask(ipv4_prefix, ipv4_netmask, sizeof(ipv4_netmask));
    if (ret != 0)
    {
        printf("ipv4 prefix to netmask failed. ret: %d, prefix: %d\n", ret, ipv4_prefix);
    }
    else
    {
        printf("ipv4 prefix to netmask success. prefix: %d, netmask: %s\n", ipv4_prefix, ipv4_netmask);
    }

    const char *hostname = "www.baidu.com";
    ret = gm_network_ping_host(hostname, 1, 200);
    if (ret != 0)
    {
        printf("ping %s failed. ret: %d\n", hostname, ret);
    }
    else
    {
        printf("ping %s success.\n", hostname);
    }


    return 0;
}
