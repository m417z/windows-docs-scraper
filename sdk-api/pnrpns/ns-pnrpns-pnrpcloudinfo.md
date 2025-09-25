# PNRPCLOUDINFO structure

## Description

The **PNRPCLOUDINFO** structure is pointed to by the **lpBlob** member of the [WSAQUERYSET](https://learn.microsoft.com/windows/desktop/P2PSdk/winsock-nsp-reference-links) structure.

## Members

### `dwSize`

Specifies the size of this structure.

### `Cloud`

Specifies the network cloud information stored in a [PNRP_CLOUD_ID](https://learn.microsoft.com/windows/desktop/api/pnrpdef/ns-pnrpdef-pnrp_cloud_id) structure.

### `enCloudState`

Specifies the state of the network cloud. Valid values are specified by [PNRP_CLOUD_STATE](https://learn.microsoft.com/windows/desktop/api/pnrpdef/ne-pnrpdef-pnrp_cloud_state).

### `enCloudFlags`

Indicates if the cloud name is valid on the network or only valid on the current computer. Valid values are specified by [PNRP_CLOUD_FLAGS](https://learn.microsoft.com/windows/desktop/api/pnrpdef/ne-pnrpdef-pnrp_cloud_flags).

## See also

[PNRP and BLOB](https://learn.microsoft.com/windows/desktop/P2PSdk/pnrp-and-blob)

[PNRP and WSALookupServiceBegin](https://learn.microsoft.com/windows/desktop/P2PSdk/pnrp-and-wsalookupservicebegin)

[PNRP and WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/P2PSdk/pnrp-and-wsalookupservicenext)

[PNRP and WSAQUERYSET](https://learn.microsoft.com/windows/desktop/P2PSdk/pnrp-and-wsaqueryset)

[PNRP_CLOUD_FLAGS](https://learn.microsoft.com/windows/desktop/api/pnrpdef/ne-pnrpdef-pnrp_cloud_flags)

[PNRP_CLOUD_ID](https://learn.microsoft.com/windows/desktop/api/pnrpdef/ns-pnrpdef-pnrp_cloud_id)

[PNRP_CLOUD_STATE](https://learn.microsoft.com/windows/desktop/api/pnrpdef/ne-pnrpdef-pnrp_cloud_state)

[WSAQUERYSET](https://learn.microsoft.com/windows/desktop/P2PSdk/winsock-nsp-reference-links)