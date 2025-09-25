# _WWAN_SYS_CAPS_INFO structure

## Description

The **WWAN_SYS_CAPS_INFO** structure represents the modem's system capability.

## Members

### `NumberOfExecutors`

Denotes the number of *executors* (MBB instances) that are supported by the modem in its current configuration.

### `NumberOfSlots`

Denotes the number of slots that are physically present on the modem. Each slot reported must be capable of receiving a UICC card; the slots themselves can be a heterogeneous mix if needed - mini SIM, micro SIM, nano SIM, or any standard as defined by ETSI. The number of slots **must** be at least equal to or greater than the number of executors supported. The "greater than" provision allows for the use of non-telephony UICC cards (such as for security, NFC, etc.).

### `Concurrency`

Denotes the number of executors that may be active at the same time, where 1 ≤ Concurrency ≤ NumberOfExecutors. For example, a dual-standby modem would have a **Concurrency** of 1 while a dual-active modem would have a **Concurrency** of 2.

### `ModemID`

A unique 64-bit number that identifies the modem. This is required to distinguish one modem from others if there is more than one modem present in a device. The modem ID should be constant across reboots or device removal and insertion.

## See also

[NDIS_STATUS_WWAN_SYS_CAPS_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-sys-caps)

[NDIS_WWAN_SYS_CAPS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_sys_caps_info)

[OID_WWAN_SYS_CAPS_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-sys-caps)