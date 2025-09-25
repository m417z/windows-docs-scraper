# _DXGKARG_GETVIRTUALGPUPROFILE structure

## Description

Arguments used to get virtual GPU profile.

## Members

### `PartitionCount`

The total number of partitions available for this detailed configuration.

### `VirtualizationFlags`

The flags define how the physical hardware of the partitionable GPU is virtualized. The possible values are:

* DXGK_VIRTUALIZED_UNIQUE_RID - Setting the flag means that the GPU Partitions has a unique requestor ID on the PCI-E fabric
* DXGK_VIRTUALIZED_ACS_CAPABLE - This flag states that ACS (access Control Services) is supported by the device and should be used to provide device security. ACS is generally required, as without ACS, a device could do peer to peer access of other devices bypassing the IOMMU. ACS is not required for devices in the Root Complex, or devices that do not support any form of Peer to Peer access.

On the Server SKU the default security policy requires the driver to set both flags.

To disable the security policy set the following registry keys:

> DWORD HKLM\SOFTWARE\Policies\Microsoft\Windows\HyperV\RequireSecureDeviceAssignment = 0
> DWORD HKLM\SOFTWARE\Policies\Microsoft\Windows\HyperV\RequireSupportedDeviceAssignment = 0

### `ProfileCapability`

The profile capabilities for each partition, specified by the kernel mode driver. The capabilities are memory, encode, decode and compute. For each capability the following information is provided by the driver:

* TotalValue - Total amount in this partition configuration.
* AvailableValue - Currently available amount in this partition configuration. This value changes as vGPUs start and stop running.
* MinPartitionValue - Minimum value for each partition in this partition configuration.
* MaxPartitionValue - Maximum value for each partition in this partition configuration.
* OptimalPartitionValue - Optimal value for each partition in this partition configuration.

The meaning of the capability values depend on the capability type. For memory it is the number of bytes. For compute it is the number of gigaflops of 16fp instructions. For video Encode/Decode it is roughly in blocks of 540p capability. 1 is 540p60, 2 is 720p60, 4 is 1080p60, 4Kp60 is 16, etc.

## Remarks

## See also