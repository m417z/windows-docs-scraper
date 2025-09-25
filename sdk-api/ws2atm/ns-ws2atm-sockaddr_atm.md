# sockaddr_atm structure

## Description

The Windows Sockets
**sockaddr_atm** structure stores socket address information for ATM sockets.

## Members

### `satm_family`

Identifies the address family, which is AF_ATM in this case.

### `satm_number`

Identifies the ATM address that could be either in E.164 or NSAP-style ATM End Systems Address format. This field will be mapped to the called party number information element (IE) if it is specified in
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) and
[WSPBind](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566268(v=vs.85)) for a listening socket, or in
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect),
[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect),
[WSPConnect](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566275(v=vs.85)),
[WSAJoinLeaf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsajoinleaf), or
[WSPJoinLeaf](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpwspjoinleaf) for a connecting socket. It will be mapped to the Calling Party Number IE if specified in
**bind** and
**WSPBind** for a connecting socket.

### `satm_blli`

Identifies the fields in the B-LLI information element that are used along with **satm_bhli** to identify an application. See
[ATM_BLLI](https://learn.microsoft.com/windows/desktop/api/ws2atm/ns-ws2atm-atm_blli) for more details. Note that the B-LLI layer two information is treated as not present if its **Layer2Protocol** field contains SAP_FIELD_ABSENT, or as a wildcard if it contains SAP_FIELD_ANY. Similarly, the B-LLI layer three information is treated as not present if its **Layer3Protocol** field contains SAP_FIELD_ABSENT, or as a wildcard if it contains SAP_FIELD_ANY.

### `satm_bhli`

Identifies the fields in the B-HLI information element that are used along with **satm_blli** to identify an application. See
[ATM_BHLI](https://learn.microsoft.com/windows/desktop/api/ws2atm/ns-ws2atm-atm_bhli) for information about the
**ATM_BHLI** structure.

**Note** **satm_bhli** is treated as not present if its **HighLayerInfoType** field contains SAP_FIELD_ABSENT, or as a wildcard if it contains SAP_FIELD_ANY.

## Remarks

For listening sockets, the **sockaddr_atm** structure is used in
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)/[WSPBind](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566268(v=vs.85)) to register a Service Access Point (SAP) to receive incoming connection requests destined to this SAP. SAP registration is used to match against the SAP specified in an incoming connection request to determine which listening socket is to receive this request. In the current specification, overlapping registration is not allowed. Overlapping registration is defined as having more than one registered SAP to potentially match the SAP specified in any incoming connection request.
[Listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen) and
[WSPListen](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566297(v=vs.85)) will return the error code WSAEADDRINUSE if the SAP associated with the listening socket overlaps with any currently registered SAPs in the system.

The fields in a SAP to be registered must contain either a valid value, or one of two special manifest constants: SAP_FIELD_ABSENT or SAP_FIELD_ANY.

SAP_FIELD_ABSENT simply means that this field is not presented as part of a SAP. SAP_FIELD_ANY means using wildcards.

Note that the requirement of nonoverlapping registration does not preclude using wildcards. For example, it is possible to have two registered SAPs that both contain SAP_FIELD_ANY in some fields and different values in other fields.

**Note** The called party ATM number is mandatory, thus the **satm_number** field cannot contain SAP_FIELD_ABSENT.

For connecting sockets, the **sockaddr_atm** structure is used to specify the destination SAP in
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)/[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)/[WSPConnect](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566275(v=vs.85)) for point-to-point connections, and
[WSAJoinLeaf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsajoinleaf)/[WSPJoinLeaf](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpwspjoinleaf) for point-to-multipoint connections. The fields in the destination SAP of a connecting socket must contain either a valid value or SAP_FIELD_ABSENT, that is, SAP_FIELD_ANY is not allowed.

Furthermore, SAP_FIELD_ABSENT is not allowed for the **satm_number** field. The destination SAP is used to match against all the registered SAPs in the destination computer to determine the forwarding destination for this connection request. If each and every field of the destination SAP of an incoming request either equals the corresponding field of a registered SAP, or the corresponding field contains the SAP_FIELD_ANY, the listening socket associated with this registered SAP will receive the incoming connection request.

If
[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind) and/or
[WSPBind](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566268(v=vs.85)) are used on a connecting socket to specify the calling party ATM address, the **satm_blli** and **satm_bhli** fields should be ignored and the ones specified in
[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect),
[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect), or
[WSPConnect](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566275(v=vs.85)) will be used.

## See also

[ATM_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2atm/ns-ws2atm-atm_address)

[ATM_BHLI](https://learn.microsoft.com/windows/desktop/api/ws2atm/ns-ws2atm-atm_bhli)

[ATM_BLLI](https://learn.microsoft.com/windows/desktop/api/ws2atm/ns-ws2atm-atm_blli)

[WSAConnect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaconnect)

[WSAJoinLeaf](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsajoinleaf)

[WSPBind](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566268(v=vs.85))

[WSPConnect](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566275(v=vs.85))

[WSPJoinLeaf](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpwspjoinleaf)

[WSPListen](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff566297(v=vs.85))

[bind](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-bind)

[connect](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-connect)

[listen](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-listen)