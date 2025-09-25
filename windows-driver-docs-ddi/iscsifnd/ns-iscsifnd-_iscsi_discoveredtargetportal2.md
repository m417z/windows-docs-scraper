# _ISCSI_DiscoveredTargetPortal2 structure

## Description

The ISCSI_DiscoveredTargetPortal2 structure provides information that is associated with a discovered target portal.

## Members

### `Socket`

The socket number of the portal.

### `Address`

The network address of the portal.

### `SecurityBitmap`

A bitmap, which is defined in the *iSNS specification*, that indicates the security characteristics of logon connections that are made to this target portal. The following table describes possible security flag values.

| Security flags | Meaning |
| --- | --- |
| ISCSI_SECURITY_FLAG_TUNNEL_MODE_PREFERRED | The initiator HBA should log on targets by using IPsec tunnel mode. If this bit is not set IPsec tunnel mode is not required. |
| ISCSI_SECURITY_FLAG_TRANSPORT_MODE_PREFERRED | The initiator HBA should log on targets by using IPsec transport mode. If this bit is not set IPsec transport mode is not required. |
| ISCSI_SECURITY_FLAG_PFS_ENABLED | The initiator HBA should log on targets with Perfect Forward Secrecy (PFS) mode enabled; otherwise, the initiator HBA should make the session connection with PFS mode disabled. |
| ISCSI_SECURITY_FLAG_AGGRESSIVE_MODE_ENABLED | The initiator HBA should log on targets with aggressive mode enabled. If this bit is not set the initiator HBA should make the session connection with aggressive mode disabled. |
| ISCSI_SECURITY_FLAG_MAIN_MODE_ENABLED | The initiator HBA should log on targets with main mode enabled. If this bit is not set the initiator HBA should make the session connection with main mode disabled. |
| ISCSI_SECURITY_FLAG_IKE_IPSEC_ENABLED | The initiator HBA should log on targets with the IKE/IPsec protocol enabled. If this bit is not set the IKE/IPsec protocol is disabled. |
| ISCSI_SECURITY_FLAG_VALID | The other mask values are valid. If this bit is not set security flags are not specified.. |

For more information about how to configure the default security characteristics that are assigned of the target portal in the registry, see the Remarks section.

### `KeySize`

The size, in bytes, of the encryption key in the **Key** member.

### `Key`

A variable-length array of characters that contains the encryption key that is associated with the portal address.

## Remarks

The ISCSI_DiscoveredTargetPortal2 structure is a superset of the information that is provided by the [ISCSI_DiscoveredTargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtargetportal) structure, which only defines the target portal address. In addition to the network address of the target portal, the ISCSI_DiscoveredTargetPortal2 structure contains information about the target portal's security characteristics.

If the iSNS server does not assign a security bitmap to the target portal, the operating system associates the bitmap in the **DefaultSecurityBitmap** registry value with the portal. The **DefaultSecurityBitmap** registry value is located under the following registry key: **HKLM\Software\Microsoft\Windows NT\Current Version\ISCSI\Discovery Values**.

The default security bitmap is useful in cases where the target portal is configured for IPsec but does not support iSNS.

In general, management applications should use the iSCSI client PSKey command to configure the security bitmap for a target portal. But if there are a large number of portals that have the same security bitmap, the default security bitmap is a good way to automatically assign the same bitmap to all portals.

The WMI tool suite automatically generates a declaration of the ISCSI_DiscoveredTargetPortal2 structure when it compiles the [ISCSI_DiscoveredTargetPortal WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-discoveredtargetportal-wmi-class) in *Discover.mof*.

## See also

[ISCSI_DiscoveredTargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsifnd/ns-iscsifnd-_iscsi_discoveredtargetportal)

[ISCSI_DiscoveredTargetPortal WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/iscsi-discoveredtargetportal-wmi-class)

[ISCSI_TargetPortal](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsidef/ns-iscsidef-_iscsi_targetportal)