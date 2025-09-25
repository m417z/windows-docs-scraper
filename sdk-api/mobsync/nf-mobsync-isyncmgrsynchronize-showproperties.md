# ISyncMgrSynchronize::ShowProperties

## Description

Called by the synchronization manager when a user selects an item in the choice dialog box, and then clicks the **Properties** button.

## Parameters

### `hWndParent` [in]

Type: **HWND**

The parent **HWND** for any user interface that a registered application displays to set properties. This value can be **NULL**.

### `ItemID` [in]

Type: **REFGUID**

The item ID for properties that are requested.

## Return value

Type: **HRESULT**

This method supports the standard return values E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, and the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The properties dialog for an item is handled successfully. |

## Remarks

If a registered application provides a properties dialog box for an item, it must set the SYNCMGRITEM_HASPROPERTIES bit in the **dwFlags** member of the [SYNCMGRITEM](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgritem) structure.

If *ItemID* is GUID_NULL the handler should show the properties dialog for the overall handler.

The appearance of the displayed dialog box should be consistent with a standard property page dialog box.

## See also

[ISyncMgrSynchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronize)

[SYNCMGRITEM](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgritem)

[SYNCMGRITEMFLAGS](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgritemflags)