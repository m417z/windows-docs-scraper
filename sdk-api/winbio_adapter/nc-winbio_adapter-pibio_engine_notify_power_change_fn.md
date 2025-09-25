# PIBIO_ENGINE_NOTIFY_POWER_CHANGE_FN callback function

## Description

Called by the Windows Biometric Framework when the computer is ready to enter a low-power state or when the computer has been awakened from a low-power state. The purpose of this function is to enable the adapter to respond to transitions in the computer power state.

## Parameters

### `Pipeline` [in, out]

Pointer to the [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `PowerEventType` [in]

Indicates the nature of the change. It can be one of the following values:

* **PBT_APMSUSPEND**

The system is entering a low-power state.

* **PBT_APMRESUMEAUTOMATIC**

The system is returning from a low-power state.

* **PBT_APMPOWERSTATUSCHANGE**

The status of the system's power source is changing (e.g. the system has switched from battery to line power, or the battery is getting low).

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

When it receives a [PBT_APMPOWERSTATUSCHANGE](https://learn.microsoft.com/windows/desktop/Power/pbt-apmpowerstatuschange) event, the adapter should call the Microsoft Win32[GetSystemPowerStatus](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getsystempowerstatus) API to determine the new power status.

The biometric framework calls this adapter entry point asynchronously in the context of an arbitrary thread. It is the responsibility of the adapter to synchronize processing of this call with any other work it may be doing.

## See also

[GetSystemPowerStatus](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getsystempowerstatus)

[PBT_APMPOWERSTATUSCHANGE](https://learn.microsoft.com/windows/desktop/Power/pbt-apmpowerstatuschange)