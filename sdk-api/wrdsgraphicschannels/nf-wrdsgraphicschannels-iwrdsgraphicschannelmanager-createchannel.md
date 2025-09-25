# IWRdsGraphicsChannelManager::CreateChannel

## Description

Used to create a graphics virtual channel.

## Parameters

### `pszChannelName` [in]

Type: **const char***

The name of the channel to create. This will be one of the following values.

#### "Microsoft::Windows::RDS::Graphics"

The Remote Desktop graphics channel.

#### "rdpgrfx"

The Remote Desktop information channel.

##### 01"

The video-optimized bitmap remote data channel.

##### 01"

The video-optimized bitmap remote geometry channel.

##### 01"

The video-optimized bitmap remote control channel.

### `channelType` [in]

Type: **[WRdsGraphicsChannelType](https://learn.microsoft.com/windows/win32/api/wrdsgraphicschannels/ne-wrdsgraphicschannels-wrdsgraphicschanneltype)**

A value of the [WRdsGraphicsChannelType](https://learn.microsoft.com/windows/win32/api/wrdsgraphicschannels/ne-wrdsgraphicschannels-wrdsgraphicschanneltype) enumeration that specifies what type of channel to create. If the specified type of channel cannot be created, this method should return a channel object rather than fail.

### `ppVirtualChannel` [out, retval]

Type: **[IWRdsGraphicsChannel](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nn-wrdsgraphicschannels-iwrdsgraphicschannel)****

The address of an [IWRdsGraphicsChannel](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nn-wrdsgraphicschannels-iwrdsgraphicschannel) interface pointer that receives the channel object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWRdsGraphicsChannelManager](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nn-wrdsgraphicschannels-iwrdsgraphicschannelmanager)