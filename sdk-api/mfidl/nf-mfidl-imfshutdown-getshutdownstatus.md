# IMFShutdown::GetShutdownStatus

## Description

Queries the status of an earlier call to the [IMFShutdown::Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfshutdown-shutdown) method.

## Parameters

### `pStatus` [out]

Receives a member of the [MFSHUTDOWN_STATUS](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfshutdown_status) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. |
| **MF_E_INVALIDREQUEST** | The [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfshutdown-shutdown) method has not been called on this object. |

## Remarks

Until [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfshutdown-shutdown) is called, the **GetShutdownStatus** method returns **MF_E_INVALIDREQUEST**.

If an object's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfshutdown-shutdown) method is asynchronous, *pStatus* might receive the value **MFSHUTDOWN_INITIATED**. When the object is completely shut down, *pStatus* receives the value **MFSHUTDOWN_COMPLETED**.

## See also

[IMFShutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfshutdown)