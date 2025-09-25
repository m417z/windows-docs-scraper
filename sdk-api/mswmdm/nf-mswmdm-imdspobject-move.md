# IMDSPObject::Move

## Description

The **Move** method moves a file or folder on a media device.

## Parameters

### `fuMode` [in]

Processing mode by which to invoke the **Move** operation and the method by which to move. Specify exactly one of the following two modes. If both modes are specified, block mode is used.

| Mode | Description |
| --- | --- |
| WMDM_MODE_BLOCK | The operation will be performed using block mode processing. The call will not return until the operation is finished. |
| WMDM_MODE_THREAD | The operation will be performed using thread mode processing. The call will return immediately, and the operation will be performed in a background thread. |

The following table lists flags that indicate where the object will be moved to. One value from this table is combined with one value from the preceding Mode table by using a bitwise **OR**.

| Method of move | Description |
| --- | --- |
| WMDM_STORAGECONTROL_INSERTBEFORE | The object will be inserted before the target object. |
| WMDM_STORAGECONTROL_INSERTINTO | The object will be inserted into the target object. The target object must be a folder. If the target object is a file, this method fails. |
| WMDM_STORAGECONTROL_INSERTAFTER | The object will be inserted after the target object. |

### `pProgress` [in]

Pointer to an [IWMDMProgress](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress) interface that has been implemented by the application to track the progress of ongoing operations. This parameter is optional and should be set to **NULL** when not being used.

### `pTarget` [in]

Pointer to the target object before or after which you want to put the current object.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

A file or directory can be moved only within the same root storage. The object on which this method is called must be updated to reflect its new location.

This method is optional. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPObject Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspobject)

[IWMDMProgress Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress)

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)