# IWMDMStorageGlobals::Initialize

## Description

The **Initialize** method formats the storage medium.

## Parameters

### `fuMode` [in]

Mode used to initialize the medium. Specify exactly one of the following two modes. If both modes are specified, block mode is used.

| Mode | Description |
| --- | --- |
| WMDM_MODE_BLOCK | The operation is performed using block mode processing. The call will not return until the operation is finished. |
| WMDM_MODE_THREAD | The operation is performed using thread mode processing. The call returns immediately, and the operation is performed in a background thread. |

### `pProgress` [in]

Pointer to an **IWMDMProgress** interface implemented by an application to track the progress of the formatting operation.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

If an application uses WMDM_MODE_THREAD and passes a non-null *pProgress* parameter, the application must ensure that the object to which *pProgress* belongs is not destroyed until the read operation completes, because Windows Media Device Manager will send progress notifications to this object. This object can be destroyed only after it receives an [End](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress-end) notification. Failure to do this will result in access violations.

## See also

[IWMDMProgress Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress)

[IWMDMStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals)