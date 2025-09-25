# ICredentialProviderCredential::GetSubmitButtonValue

## Description

Retrieves the identifier of a field that the submit button should be placed next to in the Logon UI. The Credential UI does not call this method.

## Parameters

### `dwFieldID` [in]

Type: **DWORD**

The identifier for the field a submit button value is needed for.

### `pdwAdjacentTo` [out]

Type: **DWORD***

A pointer to a value that receives the field ID of the field that the submit button should be placed next to.

**Note to implementers:** Do not return the field ID of a bitmap in this parameter. It is not good UI design to place the submit button next to a bitmap, and doing so can cause a failure in the Logon UI.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The submit button is not labeled as such; that is simply a generic way to refer to the button you click to submit the credentials. The button normally appears as a circular button that contains an arrow pointing to the right, although this appearance could change in later releases. For more information, see [CPFT_SUBMIT_BUTTON](https://learn.microsoft.com/windows/desktop/api/credentialprovider/ne-credentialprovider-credential_provider_field_type).

You should not hide the submit button unless your credential provider always performs automatic submission. Otherwise it can be confusing to the users since they will not see a way to submit their credentials.

Call this method when assembling the Logon UI. For example usage, see the Credential Providers samples included in the Windows Software Development Kit (SDK).

.