# WRdsGraphicsChannelType enumeration

## Description

Used to specify the type of graphics virtual channel to create in the [IWRdsGraphicsChannelManager::CreateChannel](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nf-wrdsgraphicschannels-iwrdsgraphicschannelmanager-createchannel) method.

## Constants

### `WRdsGraphicsChannelType_GuaranteedDelivery:0`

The channel delivery must be guaranteed.

### `WRdsGraphicsChannelType_BestEffortDelivery:1`

The channel delivery can be lossy.

## See also

[IWRdsGraphicsChannelManager::CreateChannel](https://learn.microsoft.com/windows/desktop/api/wrdsgraphicschannels/nf-wrdsgraphicschannels-iwrdsgraphicschannelmanager-createchannel)