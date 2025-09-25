# IRemoteDesktopClientSettings::SetRdpProperty

## Description

Sets the value of a single named RDP property.

## Parameters

### `propertyName` [in]

A string that specifies the name of the property.

**Note** These string values are not case-sensitive.

The possible values are.

#### "administrative session" (Boolean)

Specifies whether the session is an administrative session. This can be one of the following values.

##### false

The session is not an administrative session.

##### True

The session is an administrative session.

#### "allow font smoothing" (Boolean)

Specifies whether font smoothing is allowed in the remote session. This can be one of the following
values.

##### false

Font smoothing is not allowed.

##### True

Font smoothing is allowed.

#### "alternate full address" (String)

Specifies an alternate name or IP address of the remote computer that you want to connect to.

#### "audiocapturemode" (Boolean)

Specifies the audio input capture mode. This can be one of the following values.

##### false

Do not capture audio input.

##### True

Capture audio input.

#### "audiomode" (Number)

Specifies where sounds are played. This can be one of the following values.

##### 0

Play sounds on the client computer.

##### 1

Play sounds on the host computer.

##### 2

Do not play sounds.

#### "authentication level" (Number)

Specifies the authentication level of the remote session. This can be one of the following values.

##### 0

None.

##### 1

Authentication required.

##### 2

Authentication negotiable.

##### 3

Authentication unspecified.

#### "connection type" (Number)

Specifies the connection type This can be one of the following values.

##### 1

Modem

##### 2

Low speed broadband

##### 3

Satellite

##### 4

High speed broadband

##### 5

WAN

##### 6

LAN

##### 7

Auto detect

#### "cookie based authentication server address" (String)

Specifies the address of the cookie-based authentication server.

#### "desktopheight" (Number)

Specifies the height, in pixels, of the virtual desktop.

#### "desktopwidth" (Number)

Specifies the width, in pixels, of the virtual desktop.

#### "disable full window drag" (Boolean)

Specifies whether showing window contents while dragging is disabled. This can be one of the following
values.

##### false

Enabled

##### True

Disabled

#### "disable menu anims" (Boolean)

Specifies whether showing menu animations is disabled. This can be one of the following values.

##### false

Enabled

##### True

Disabled

#### "disable themes" (Boolean)

Specifies whether themes are disabled. This can be one of the following values.

##### false

Enabled

##### True

Disabled

#### "disable wallpaper" (Boolean)

Specifies whether wallpapers are displayed. This can be one of the following values.

##### false

Wallpapers are displayed.

##### True

Wallpapers are not displayed.

#### "domain" (String)

Specifies the domain used to connect to the remote session.

#### "enablecredsspsupport" (Boolean)

Specifies whether to use CredSSP-based authentication for the remote session. This can be one of the
following values.

##### false

Do not use CredSSP-based authentication.

##### True

Use CredSSP-based authentication.

#### "full address" (String)

Specifies the address of the computer being connected to.

#### "gatewaycredentialssource" (Number)

Specifies the source for credentials for the Remote Desktop gateway. This can be one of the following
values.

##### 0

Prompt the user for their credentials and use NTLM authentication.

##### 1

Use a smart card for credentials.

##### 2

Use the credentials for the currently logged on user.

##### 3

Prompt the user for their credentials and use basic authentication.

##### 4

The user will select the credential source at logon.

##### 5

Use cookie-based authentication.

#### "gatewayhostname" (String)

Specifies the Remote Desktop gateway server name.

#### "gatewayprofileusagemethod" (Number)

Specifies the Remote Desktop gateway profile usage. This can be one of the following values.

##### 0

Use the gateway profile settings, if present.

##### 1

Use the explicit gateway settings, even if a gateway profile exists.

#### "gatewayusagemethod" (Number)

Specifies the Remote Desktop gateway usage. This can be one of the following values.

##### 0

Do not use a Remote Desktop gateway server. The **Bypass RD Gateway server for
local addresses** check box is cleared.

##### 1

Use the Remote Desktop gateway specified by the "gatewayhostname" property.

##### 2

Automatically detect the Remote Desktop gateway server settings.

##### 3

Use the default settings Remote Desktop gateway usage settings.

##### 4

Do not use a Remote Desktop gateway server. The **Bypass RD Gateway server for
local addresses** check box is selected.

#### "high resolution mouse" (Boolean)

Specifies the resolution mode for mouse input. This can be one of the following values.

##### false

Mouse input will be coalesced. Mouse data will be subsampled and sent according to the default
sampling rate.

##### True

Mouse input will not be coalesced. Mouse data will be sent at full resolution.

#### "loadbalanceinfo" (String)

Contains the load balancing cookie used to choose the best server for the client computer.

#### "login web page address" (String)

Specifies the address of the login webpage.

#### "pre-authentication server address" (String)

Specifies the address of the preauthentication server.

#### "prompt for credentials" (Boolean)

Specifies whether the user will be prompted for their credentials. This can be one of the following
values.

##### false

The user will not be prompted for credentials.

##### True

The user will be prompted for credentials.

#### "promptcredentialonce" (Number)

Specifies whether credential sharing for the Remote Desktop gateway is enabled. This can be one of the
following values.

##### 0

Credential sharing is disabled.

##### 1

Credential sharing is enabled.

#### "redirectclipboard" (Boolean)

Specifies whether the clipboard for the client is redirected to the remote session. This can be one of the
following values.

##### false

The clipboard is not redirected.

##### True

The clipboard is redirected.

#### "redirectprinters" (Boolean)

Specifies whether the printers for the client are redirected to the remote session. This can be one of the
following values.

##### false

The printers are not redirected.

##### True

The printers are redirected.

#### "require pre-authentication" (Number)

Specifies whether preauthentication is required. This can be one of the following values.

##### 0

Pre-authentication is not required.

##### 1

Pre-authentication is required.

#### "support url" (String)

Specifies the URL to obtain support information from.

**Boolean**

#### "use redirection server name" (Boolean)

Specifies whether a redirection server is allowed. This can be one of the following values.

##### false

A redirection server is not allowed.

##### True

A redirection server is allowed.

#### "username" (String)

Specifies the user name used to connect to the remote session.

#### "WinRTEncryptedPassword" (String)

Specifies an encrypted password. To set this property, you must perform the following actions.

1. Convert the clear text password to binary by using the
   [ConvertStringToBinary](https://learn.microsoft.com/uwp/api/windows.security.cryptography.cryptographicbuffer.convertstringtobinary)
   method on the [CryptographicBuffer](https://learn.microsoft.com/uwp/api/windows.security.cryptography.cryptographicbuffer)
   class.
2. Set the **WinRTPasswordEncoding** property by using an equivalent value for the
   encoding parameter you passed to the
   [ConvertStringToBinary](https://learn.microsoft.com/uwp/api/windows.security.cryptography.cryptographicbuffer.convertstringtobinary)
   method in step 1.
3. Call the
   [DataProtectionProvider(String)](https://learn.microsoft.com/uwp/api/Windows.Security.Cryptography.DataProtection.DataProtectionProvider)
   method by passing "LOCAL=user" for the input string.
4. Call the
   [ProtectAsync](https://learn.microsoft.com/uwp/api/windows.security.cryptography.dataprotection.dataprotectionprovider.protectasync)
   method to encrypt the binary string that contains the password.
5. Convert the
   [CryptographicBuffer](https://learn.microsoft.com/uwp/api/windows.security.cryptography.cryptographicbuffer) object
   returned by the
   [ProtectAsync](https://learn.microsoft.com/uwp/api/windows.security.cryptography.dataprotection.dataprotectionprovider.protectasync)
   method to a Base64 encoded value by using the
   [EncodeToBase64String](https://learn.microsoft.com/uwp/api/windows.security.cryptography.cryptographicbuffer.encodetobase64string)
   method.
6. Set this property (**WinRTEncryptedPassword**) with the Base64 encoded string
   obtained in step 5.

#### "WinRTPasswordEncoding" (Number)

Specifies the type of encoding that can be applied to an encrypted password. This can be one of the
following values. The default value is 1. This property must be set before setting the
**WinRTEncryptedPassword** property.

##### 0

UTF8

##### 1

UTF16LE

##### 2

UTF16BE

#### "Workspace Id" (String)

Specifies the identifier of the RemoteApp and Desktop Connection workspace which this RDP file has been
published as part of.

### `value` [in]

The new property value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRemoteDesktopClientSettings](https://learn.microsoft.com/windows/desktop/api/rdpappcontainerclient/nn-rdpappcontainerclient-iremotedesktopclientsettings)