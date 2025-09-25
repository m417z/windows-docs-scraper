# DRT_REGISTRATION structure

## Description

The **DRT_REGISTRATION** structure contains key and application data that make up a registration.

## Members

### `key`

Contains the key portion of the registration.

### `appData`

The application data associated with the key. The [DRT_DATA](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_data) structure containing this application data must point to a buffer less than 4KB in size.

## See also

[DRT_SEARCH_RESULT](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_search_result)

[DrtCreateDerivedKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtcreatederivedkey)

[DrtRegisterKey](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtregisterkey)