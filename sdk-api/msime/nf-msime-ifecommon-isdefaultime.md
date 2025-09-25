# IFECommon::IsDefaultIME

## Description

Determines if the IME specified by the class ID is the default IME on a local computer.

The name of the IME is obtained from the [Win32 keyboard layout API](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input-functions).

## Parameters

### `szName` [out]

The name of the IME for the specified class ID. Can be **NULL**.

### `cszName` [in]

The size of *szName* in bytes.

## Return value

* **S_OK** if this Microsoft IME is already the default IME.
* **S_FALSE** if this Microsoft IME is not the default IME.
* Otherwise **E_FAIL**.

## See also

[IFECommon](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifecommon)

[Win32 keyboard layout API](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input-functions)