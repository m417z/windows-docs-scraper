# DOT11EXT_PRE_ASSOCIATE_COMPLETION callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The IHV Extensions DLL calls the
**Dot11ExtPreAssociateCompletion** function to asynchronously complete a
pre-association operation initiated through a call to the
[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate) IHV Handler function.

## Parameters

### `hDot11SvcHandle` [in, optional]

The handle used by the operating system to reference the wireless LAN (WLAN) adapter. This handle
value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `hConnectSession` [in, optional]

The handle used by the operating system to reference the connection session with the basic service
set (BSS) network. This handle value was specified through a previous call to the
[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate) IHV Handler function.

### `dwReasonCode` [in]

A value that provides additional information for the completion status of the pre-association
operation. The IHV Extensions DLL must set
*dwReasonCode* to an L2_REASON_CODE_xxxx value, which are defined in
L2cmn.h.

The IHV Extensions DLL returns the general completion status of the pre-association operation through
the
*dwWin32Error* parameter. Typically, the IHV Extensions DLL sets
*dwReasonCode* to a value in the range from L2_REASON_CODE_IHV_BASE to (L2_REASON_CODE_IHV_BASE+
L2_REASON_CODE_GROUP_SIZE-1).

### `dwWin32Error` [in]

The completion status of the pre-association operation as defined by an error code within
Winerror.h. If the operation completes successfully, the IHV Extensions DLL must set
*dwWin32Error* to ERROR_SUCCESS.

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DWORD WINAPI * Dot11ExtPreAssociateCompletion(
  _In_opt_ HANDLE hDot11SvcHandle,
  _In_opt_ HANDLE hConnectSession,
  _In_     DWORD  dwReasonCode,
  _In_     DWORD  dwWin32Error
);
```

## Remarks

The IHV Extensions DLL must follow these guidelines when calling the
**Dot11ExtPreAssociateCompletion** function.

* If the pre-association operation completed successfully, the IHV Extensions DLL must set
  *dwReasonCode* to one of the following:

  + L2_REASON_CODE_SUCCESS.
  + An IHV-defined value in the range from L2_REASON_CODE_IHV_BASE to (L2_REASON_CODE_IHV_BASE+
    L2_REASON_CODE_GROUP_SIZE-1).In this situation, the IHV Extensions DLL must set
  *dwWin32Error* to ERROR_SUCCESS.
* If the pre-association operation completed with a failure, the IHV Extensions DLL must not set
  *dwReasonCode* to L2_REASON_CODE_SUCCESS. Instead, the DLL must set
  *dwReasonCode* to one of the following:

  + An appropriate L2_REASON_CODE_xxxx error value.
  + An IHV-defined value in the range from L2_REASON_CODE_IHV_BASE to (L2_REASON_CODE_IHV_BASE+
    L2_REASON_CODE_GROUP_SIZE-1).In this situation, the IHV Extensions DLL must not set
  *dwWin32Error* to ERROR_SUCCESS. Instead, the DLL must set
  *dwWin32Error* to an appropriate error code defined in
  Winerror.h
* The IHV Extensions DLL must call
  **Dot11ExtPreAssociateCompletion** to cancel all pending pre-association
  operations whenever the
  [Dot11ExtIhvAdapterReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_adapter_reset) or
  [Dot11ExtIhvDeinitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_adapter) IHV
  Handler functions are called. In this situation, the DLL must set the
  *dwWin32Error* parameter to ERROR_CANCELLED.

## See also

[Dot11ExtIhvAdapterReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_adapter_reset)

[Dot11ExtIhvDeinitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_deinit_adapter)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[Native 802.11 IHV Handler
Functions](https://learn.microsoft.com/windows-hardware/drivers/network/native-802-11-ihv-handler-functions)

[Dot11ExtIhvPerformPreAssociate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_perform_pre_associate)