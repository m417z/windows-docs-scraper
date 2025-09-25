## Description

Provides customization options for a single field in a logon or credential UI. Used by [ICredentialProviderCredentialEvents2::SetFieldOptions](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredentialevents2-setfieldoptions) and [ICredentialProviderCredentialWithFieldOptions::GetFieldOptions](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredentialwithfieldoptions-getfieldoptions).

## Constants

### `CPCFO_NONE:0`

Default. Don't show the "password reveal" glyph, and use the standard on-screen keyboard layout.

### `CPCFO_ENABLE_PASSWORD_REVEAL:0x1`

Display the "password reveal" glyph in a password entry box. When this glyph is held down by the user, the entry in the password box is shown in plain text. The glyph is shown here:

![Password reveal glyph](https://learn.microsoft.com/windows/win32/api/credentialprovider/images/PasswordReveal.png)

### `CPCFO_IS_EMAIL_ADDRESS:0x2`

The field will contain an e-mail address. The on-screen keyboard should be optimized for that input (showing the .com and @ keys on the primary keyboard layout). This option is used with Microsoft account credentials.

### `CPCFO_ENABLE_TOUCH_KEYBOARD_AUTO_INVOKE:0x4`

When enabled, the touch keyboard will be automatically invoked. This should be set only on the **CPFG_CREDENTIAL_PROVIDER_LOGO** field.

### `CPCFO_NUMBERS_ONLY:0x8`

The field will only allow numerals to be entered. The on-screen keyboard should be optimized for that input (showing only a number keypad on the primary keyboard layout). This should be set only on the **CPFT_PASSWORD_TEXT** field

### `CPCFO_SHOW_ENGLISH_KEYBOARD:0x10`

Show the English keyboard.

## See also

[ICredentialProviderCredentialEvents2::SetFieldOptions](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredentialevents2-setfieldoptions)

[ICredentialProviderCredentialWithFieldOptions::GetFieldOptions](https://learn.microsoft.com/windows/desktop/api/credentialprovider/nf-credentialprovider-icredentialprovidercredentialwithfieldoptions-getfieldoptions)