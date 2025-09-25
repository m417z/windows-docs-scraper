## Description

Represents a custom Domain Name System (DNS) server, used in the Winsock APIs.

## Members

### `ai_servertype`

The type of DNS server. Can be one of the following values.

| Constant | Value | Meaning |
|----------------------------|--------|----------------------------|
| **AI_DNS_SERVER_TYPE_UDP** | 1 | A regular DNS server. |
| **AI_DNS_SERVER_TYPE_DOH** | 2 | A *DNS-over-HTTPS* server. |

### `ai_flags`

A bitmap containing any of the following options.

| Constant | Value | Meaning |
|-|-|-|
| **AI_DNS_SERVER_UDP_FALLBACK** | 0x1 | This server can also be used for non-secure name resolution. |

### `ai_addrlen`

The length in bytes of the socket address structure that *ai_addr* points to.

### `ai_addr`

A pointer to a socket address structure containing the address of the custom server. Only **SOCKADDR_IN** and **SOCKADDR_IN6** structures are supported. The *sa_family* member must be set to **AF_INET** or **AF_INET6**. The rest of the structure must be zeroed out, with the exception of the **SOCKADDR_IN::sin_addr** member for IPv4, or **SOCKADDR_IN6::sin6_addr** for IPv6.

### `ai_template`

If *ai_servertype* is set to **AI_DNS_SERVER_TYPE_DOH**, then this member must point to a **NULL**-terminated wide string representing the *DNS-over-HTTPS* template for this server.

If *ai_servertype* is set to **AI_DNS_SERVER_TYPE_UDP**, then this field must be **NULL**.

## Remarks

## See also

* [ADDRINFOEX6](https://learn.microsoft.com/windows/win32/api/ws2def/ns-ws2def-addrinfoex6)