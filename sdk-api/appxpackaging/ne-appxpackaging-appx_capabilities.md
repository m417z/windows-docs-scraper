# APPX_CAPABILITIES enumeration

## Description

Specifies the capabilities or privileges requested by a package.

## Constants

### `APPX_CAPABILITY_INTERNET_CLIENT`

Your Internet connection for outgoing connections to the Internet.

### `APPX_CAPABILITY_INTERNET_CLIENT_SERVER`

Your Internet connection, including incoming unsolicited connections from the Internet – the app can send information to or from your computer through a firewall. You do not need to declare **APPX_CAPABILITY_INTERNET_CLIENT** if this capability is declared.

### `APPX_CAPABILITY_PRIVATE_NETWORK_CLIENT_SERVER`

A home or work network – the app can send information to or from your computer and other computers on the same network.

### `APPX_CAPABILITY_DOCUMENTS_LIBRARY`

Your documents library, including the capability to add, change, or delete files. The package can access only file types that it has declared in the manifest. The app cannot access document libraries on HomeGroup computers.

### `APPX_CAPABILITY_PICTURES_LIBRARY`

Your pictures library, including the capability to add, change, or delete files. This capability also includes pictures libraries on HomeGroup computers, along with picture file types on locally connected media servers.

### `APPX_CAPABILITY_VIDEOS_LIBRARY`

Your videos library, including the capability to add, change, or delete files. This capability also includes videos libraries on HomeGroup computers, along with video file types on locally connected media servers.

### `APPX_CAPABILITY_MUSIC_LIBRARY`

Your music library and playlists, including the capability to add, change, or delete files. This capability also includes music libraries and playlists in the music library on HomeGroup computers, plus music file types on locally connected media servers.

### `APPX_CAPABILITY_ENTERPRISE_AUTHENTICATION`

Your Windows credentials, for access to a corporate intranet. This application can impersonate you on the network.

### `APPX_CAPABILITY_SHARED_USER_CERTIFICATES`

Software and hardware certificates or a smart card – used to identify you in the app. This capability may be used by your employer, bank, or government services to identify you.

### `APPX_CAPABILITY_REMOVABLE_STORAGE`

Removable storage, such as an external hard drive or USB flash drive, or MTP portable device, including the capability to add, change, or delete specific files. This package can only access file types that it has declared in the manifest.

### `APPX_CAPABILITY_APPOINTMENTS`

### `APPX_CAPABILITY_CONTACTS`

## Remarks

The **APPX_CAPABILITIES** enumeration specifies privileges that a package declares in the package manifest. If a capability is not explicitly declared, then the default is no access to that capability. If a capability is declared then a package may still not have the particular capability for reasons such as the capability does not exist on the system or there are other security policies in place that limit the capability.

## See also

[IAppxManifestReader::GetCapabilites](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxmanifestreader-getcapabilities)