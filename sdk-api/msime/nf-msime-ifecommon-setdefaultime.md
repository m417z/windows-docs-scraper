# IFECommon::SetDefaultIME

## Description

Allows the Microsoft IME to become the default IME in the keyboard layout.

This method only applies when Microsoft IME uses the Input Method Manager (IMM) of the operating system.

## Return value

* **S_OK** if successful.
* **IFEC_S_ALREADY_DEFAULT** if this Microsoft IME is already the default IME.
* Otherwise **E_FAIL**.

## See also

[IFECommon](https://learn.microsoft.com/windows/desktop/api/msime/nn-msime-ifecommon)