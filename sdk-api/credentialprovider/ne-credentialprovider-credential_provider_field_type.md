# CREDENTIAL_PROVIDER_FIELD_TYPE enumeration

## Description

Specifies a type of credential field. Used by [CREDENTIAL_PROVIDER_FIELD_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/credentialprovider/ns-credentialprovider-credential_provider_field_descriptor).

## Constants

### `CPFT_INVALID:0`

The value is invalid. This is a safe initialization value, as fields do not default to any given type.

### `CPFT_LARGE_TEXT`

A stand-alone text label is drawn in the larger of two font sizes.

### `CPFT_SMALL_TEXT`

A stand-alone text label is drawn in the smaller of two font sizes.

### `CPFT_COMMAND_LINK`

An uneditable string that a user may click to perform an action. The credential provider is informed of the user's click, and then performs the requested action. Use [CommandLinkClicked](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredential-commandlinkclicked) in your credential provider to respond to the click.

### `CPFT_EDIT_TEXT`

An edit box. Users may provide credential information by typing in this box.

### `CPFT_PASSWORD_TEXT`

A special edit control that displays its string as a series of password characters, such as the asterisk character (*). Otherwise this functions the same as **CPFT_EDIT_TEXT**.

### `CPFT_TILE_IMAGE`

A bitmap that is shown as the user tile image. This bitmap cannot be edited. All credential providers must contain no more than one **CPFT_TILE_IMAGE**. If no image is specified, Logon UI and Credential UI will supply a default tile image.

### `CPFT_CHECKBOX`

A checkbox control that allows for checked and unchecked states.

### `CPFT_COMBOBOX`

A combobox control that allows users to select an option from a defined set of choices.

### `CPFT_SUBMIT_BUTTON`

This field appears as a button on the credential tile. Pressing the button lets the user submit their credentials. There is exactly one **CPFT_SUBMIT_BUTTON** on any credential tile. Unlike Logon UI, which draws a special submit button in the tile layout, Credential UI hides this field and renders a single submit button for all credentials.

## Remarks

This type enables you to specify the different elements your credential provider will need to display to the user. Credential providers are not responsible for drawing their own UI, so they need to define the elements that are necessary. This type is one of the elements to support that mechanism.