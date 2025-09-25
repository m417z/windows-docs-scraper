# NPSearchDialog function

## Description

Enables network vendors to supply their own form of browsing and search, beyond the hierarchical view presented in the **Connection** dialog box. If a network provider supports this function, the **Connection** dialog box will enable the **Search** button when the selected item belongs to that provider. If the user hits the **Search** button, the **Connection** dialog box calls **NPSearchDialog** to handle the user request.

## Parameters

### `hwndParent` [in]

Handle of the window to be used as the parent window of the dialog box.

### `lpNetResource` [in]

Pointer to the currently selected item in the **Network Connections** dialog box. A provider may choose to ignore this field.

### `lpBuffer` [out]

Pointer to a buffer that will receive the result of the search.

### `cbBuffer` [out]

**DWORD** that will specify the size of the buffer passed in.

### `lpnFlags` [in]

Pointer to a **DWORD** of flags that the provider can set to force certain actions after the dialog box is dismissed. The only flag supported is WNSRCH_REFRESH_FIRST_LEVEL, which forces MPR to collapse then expand and refresh the first level below this provider after the dialog box is dismissed.

## Return value

If the function succeeds and the user has clicked **OK**, **NPSearchDialog** should return WN_SUCCESS. Otherwise, it should return an error value, which can be one of the following. All other errors should be handled or reported directly by the provider's dialog box.

| Return code | Description |
| --- | --- |
| **WN_CANCEL** | The user canceled the operation. |
| **WN_MORE_DATA** | The input buffer is too small. |

## Remarks

If the provider does not support enumeration, then the action associated with double-clicking the provider's entry will be to invoke its **Search** dialog box.