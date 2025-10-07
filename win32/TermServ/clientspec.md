# ClientSpec enumeration

Used with the [**ClientProtocolSpec**](https://learn.microsoft.com/windows/win32/termserv/imsrdpclientadvancedsettings8-clientprotocolspec) property to specify the remote desktop protocol used between the client and the server.

## Constants

**FullMode**

The protocol is full Windows 8 Remote Desktop protocol.

**ThinClientMode**

The protocol is limited to using the Windows 7 with SP1 RemoteFX codec and a smaller cache. All other codecs are disabled. This protocol has the smallest memory footprint.

**SmallCacheMode**

The protocol is the same as **FullMode**, except it uses a smaller cache.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8<br> |
| Minimum supported server<br> | Windows Server 2012<br> |
| Type library<br> | MsTscAx.dll |

## See also

[**IMsRdpClientAdvancedSettings8::ClientProtocolSpec**](https://learn.microsoft.com/windows/win32/termserv/imsrdpclientadvancedsettings8-clientprotocolspec)

