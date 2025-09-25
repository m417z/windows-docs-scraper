# SspiPromptForCredentialsA function

## Description

Allows a [Security Support Provider Interface](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SSPI) application to prompt a user to enter credentials.

## Parameters

### `pszTargetName` [in]

The name of the target to use.

### `pUiInfo` [in]

A pointer to a [CREDUI_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credui_infoa) structure that contains information for customizing the appearance of the dialog box that this function displays.

If the **hwndParent** member of the [CREDUI_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credui_infoa) structure is not **NULL**, this function displays a modal dialog box centered on the parent window.

If the **hwndParent** member of the [CREDUI_INFO](https://learn.microsoft.com/windows/desktop/api/wincred/ns-wincred-credui_infoa) structure is **NULL**, the function displays a dialog box centered on the screen.

This function ignores the **hbmBanner** member of the **CREDUI_INFO** structure.

### `dwAuthError` [in]

A Windows error code, defined in Winerror.h, that is displayed in the dialog box. If credentials previously collected were not valid, the caller uses this parameter to pass the error message from the API that collected the credentials (for example, Winlogon) to this function. The corresponding error message is formatted and displayed in the dialog box. Set the value of this parameter to zero to display no error message.

### `pszPackage` [in]

The name of the security package to use.

### `pInputAuthIdentity` [in]

An identity structure that is used to populate credential fields in the dialog box. To leave the credential fields empty, set the value of this parameter to **NULL**.

### `ppAuthIdentity` [out]

An identity structure that represents the credentials this function collects.

When you have finished using this structure, free it by calling the [SspiFreeAuthIdentity](https://learn.microsoft.com/windows/desktop/api/sspi/nf-sspi-sspifreeauthidentity) function.

### `pfSave` [in, out, optional]

A pointer to a Boolean value that, on input, specifies whether the **Save** check box is selected in the dialog box that this function displays. On output, the value of this parameter specifies whether the **Save** check box was selected when the user clicked the **Submit** button in the dialog box. Set this parameter to **NULL** to ignore the **Save** check box.

This parameter is ignored if the **CREDUIWIN_CHECKBOX** flag is not set in the *dwFlags* parameter.

### `dwFlags` [in]

Flags that determine the behavior of this function. The following flag is currently defined.

| Value | Meaning |
| --- | --- |
| **SSPIPFC_CREDPROV_DO_NOT_SAVE**<br><br>0x00000001 | The value of the *pfSave* parameter is ignored, and the credentials collected by this function are not saved.<br><br>**Windows 7 and Windows Server 2008 R2:** The value of the *pfSave* parameter is ignored, and the credentials collected by this function are not saved. Only the name of this possible value was SSPIPFC_SAVE_CRED_BY_CALLER. |
| **SSPIPFC_NO_CHECKBOX**<br><br>0x00000002 | The value signifies that password and smart card credential providers will not display the "Remember my credentials" checkbox to the user. The **SspiPromptForCredentials** function passes this flag value, SSPIPFC_NO_CHECKBOX, in the *pvInAuthBuffer* parameter of [CredUIPromptForWindowsCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforwindowscredentialsa) function. |

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code.

## Remarks

> [!NOTE]
> The sspi.h header defines SspiPromptForCredentials as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).