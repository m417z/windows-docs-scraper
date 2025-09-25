# SLIsGenuineLocal function

## Description

Checks whether the specified application is a genuine Windows installation.

## Parameters

### `pAppId` [in]

A pointer to an **SLID** structure that specifies the application to check.

### `pGenuineState` [out]

A pointer to a value of the [SL_GENUINE_STATE](https://learn.microsoft.com/windows/desktop/api/slpublic/ne-slpublic-sl_genuine_state) enumeration that specifies the state of the installation.

### `pUIOptions` [in, out, optional]

A pointer to an [SL_NONGENUINE_UI_OPTIONS](https://learn.microsoft.com/windows/desktop/api/slpublic/ns-slpublic-sl_nongenuine_ui_options) structure that specifies a dialog box to display if the installation is not genuine. If the value of this parameter is **NULL**, no dialog box is displayed.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

This function checks the **Tampered** flag of the license associated with the specified application. If the license is not valid, or if the **Tampered** flag of the license is set, the installation is not considered valid.