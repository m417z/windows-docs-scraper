# IMDSPStorageGlobals::Initialize

## Description

The **Initialize** method formats the storage medium. This method is optional. However, this method should be implemented if the device supports this functionality. If this method is not implemented, [IMDSPStorageGlobals::GetCapabilities](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorageglobals-getcapabilities) must return WMDM_STORAGECAP_NOT_INITIALIZABLE in addition to any other flags. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## Parameters

### `fuMode` [in]

Mode used to initialize the medium. Specify exactly one of the following two modes. If both modes are specified, block mode is used.

| Mode | Description |
| --- | --- |
| WMDM_MODE_BLOCK | The operation is performed using block mode processing. The call is not returned until the operation is finished. |
| WMDM_MODE_THREAD | The operation is performed using thread mode processing. The call returns immediately and the operation is performed in a background thread. |

### `pProgress` [in]

Pointer to an **IWMDMProgress** interface implemented by an application to track the progress of the formatting operation. This parameter can be **NULL**.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

If WMDM_MODE_BLOCK is specified, **Initialize** does not return until formatting is finished. If the WMDM_MODE_THREAD is specified, the call returns immediately and the caller can use the **IMDSPStorageGlobals::GetStatus** method to track the initializing operation.

## See also

[IMDSPStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorageglobals)

[IMDSPStorageGlobals::GetCapabilities](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorageglobals-getcapabilities)

[IMDSPStorageGlobals::GetStatus](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorageglobals-getstatus)

[IWMDMProgress Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress)