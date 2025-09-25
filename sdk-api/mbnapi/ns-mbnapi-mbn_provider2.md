## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

The **MBN_PROVIDER2** structure represents a network service provider. It is used by many of the provider-specific methods of the [IMbnMultiCarrier](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrier) interface and provides an extension to [MBN_PROVIDER](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_provider) to support multi-carrier. This extension contains the signal strength of each provider, which helps to determine which provider a user should connect to.

## Members

### `provider`

Contains a single-carrier [MBN_PROVIDER](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_provider) structure.

### `cellularClass`

Contains a [MBN_CELLULAR_CLASS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_cellular_class) that specifies which cellular class the provider uses.

### `signalStrength`

Contains the signal quality received by the device as defined by [GetSignalStrength](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsignal-getsignalstrength).

### `signalError`

Contains the signal error rate as defined by [GetSignalError](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsignal-getsignalerror).

## See also

[MBN_PROVIDER](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_provider)