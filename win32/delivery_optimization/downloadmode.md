# DownloadMode enumeration

Defines the different download modes that Delivery Optimization uses.

## Constants

**DownloadMode_CdnOnly**

This setting disables peer-to-peer caching but still allows Delivery Optimization to download content from Microsoft servers. This mode uses additional metadata provided by the Delivery Optimization cloud services for a peerless reliable and efficient download experience.

**DownloadMode_Lan**

This default operating mode for Delivery Optimization enables peer sharing on the same network.

**DownloadMode_Group**

When group mode is set, the group is automatically selected based on the device s Active Directory Domain Services (AD DS) site (Windows 10, version 1607) or the domain the device is authenticated to (Windows 10, version 1511). In group mode, peering occurs across internal subnets, between devices that belong to the same group, including devices in remote offices. You can use the GroupID option to create your own custom group independently of domains and AD DS sites. Group download mode is the recommended option for most organizations looking to achieve the best bandwidth optimization with Delivery Optimization.

**DownloadMode_Internet**

Enable Internet peer sources for Delivery Optimization.

**DownloadMode_Simple**

Simple mode disables the use of Delivery Optimization cloud services completely (for offline environments). Delivery Optimization switches to this mode automatically when the Delivery Optimization cloud services are unavailable, unreachable or when the content file size is less than 10 MB. In this mode, Delivery Optimization provides a reliable download experience, with no peer-to-peer caching.

**DownloadMode_Bypass**

Bypass Delivery Optimization and use BITS, instead. For example, select this mode so that clients can use BranchCache.

## Requirements

| Requirement | Value |
|-------------------------------|----------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1709 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server, version 1709 \[desktop apps only\]<br> |
| Header<br> | Deliveryoptimization.h |