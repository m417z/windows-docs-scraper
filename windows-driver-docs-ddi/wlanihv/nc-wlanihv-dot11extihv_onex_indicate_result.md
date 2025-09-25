# DOT11EXTIHV_ONEX_INDICATE_RESULT callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvOneXIndicateResult* IHV Handler function when it completes an 802.1X authentication
operation with the access point (AP).

## Parameters

### `hIhvExtAdapter` [in, optional]

The handle used by the IHV Extensions DLL to reference the wireless LAN (WLAN) adapter. This
handle value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `msOneXResult` [in]

The result of the 802.1X authentication operation specified through a
[DOT11_MSONEX_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ne-wlanihv-_dot11_msonex_result) enumeration
value.

### `pDot11MsOneXResultParams` [in, optional]

A pointer to a
[DOT11_MSONEX_RESULT_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11_msonex_result_params) structure that contains result parameters.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_ONEX_INDICATE_RESULT Dot11ExtIhvOneXIndicateResult;

DWORD APIENTRY Dot11ExtIhvOneXIndicateResult(
  _In_opt_ HANDLE                      hIhvExtAdapter,
  _In_     DOT11_MSONEX_RESULT         msOneXResult,
  _In_opt_ PDOT11_MSONEX_RESULT_PARAMS pDot11MsOneXResultParams
)
{ ... }
```

## Remarks

The IHV Extensions DLL can initiate an 802.1X authentication operation by using the 802.1X module of
the Native 802.11 framework. This allows the DLL to make use of the standard extensible authentication
protocol (EAP) algorithms that are supported by the operating system.

The IHV Extensions DLL initiates the 802.1X authentication operation by calling the
[Dot11ExtStartOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_start) function.
**Dot11ExtStartOneX** can only be called either during a post-association operation or after the
operation has completed. For more information about this operation, see
[Post-Association Operations](https://learn.microsoft.com/windows-hardware/drivers/network/post-association-operations).

After the operating system has completed the 802.1X authentication operation, it calls the
*Dot11ExtIhvOneXIndicateResult* IHV Handler function.

For more information about using the 802.1X module for authentication, see
[Interface to the Native
802.11 802.1X Module](https://learn.microsoft.com/windows-hardware/drivers/network/interface-to-the-native-802-11-802-1x-module)

## See also

[Dot11ExtIhvReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_receive_packet)

[Dot11ExtProcessOneXPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_process_onex_packet)

[Dot11ExtStartOneX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_onex_start)

[DOT11_MSONEX_RESULT_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11_msonex_result_params)

[DOT11_MSONEX_RESULT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ne-wlanihv-_dot11_msonex_result)