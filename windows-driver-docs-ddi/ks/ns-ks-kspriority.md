## Description

The KSPRIORITY structure is used to specify priority and is used with the [**KSPROPERTY_CONNECTION_PRIORITY**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-connection-priority) property.

## Members

### `PriorityClass`

Specifies a number ranging from 1 to 0xFFFFFFFF, where 1 is least priority and 0xFFFFFFFF is the highest priority. Zero is reserved for future use. When setting a class value, 0xFFFFFFFF is used to indicate exclusive access to the resources consumed by the pin. Possible values are listed in the following table.

| PriorityClass | Description |
|---|---|
| KSPRIORITY_LOW | Specifies the lowest priority. |
| KSPRIORITY_NORMAL | Specifies normal priority. |
| KSPRIORITY_HIGH | Specifies an elevated priority. |
| KSPRIORITY_EXCLUSIVE | Specifies the highest priority, which implies exclusive access to resources. |

### `PrioritySubClass`

Specifies a number ranging from 1 to 0xFFFFFFFF, where 1 is the least priority within the class and 0xFFFFFFFF is the most priority. Zero is reserved for future use.

## Remarks

The KSPRIORITY.PrioritySubClass member allows a client to set exclusive use of resources consumed by a pin and also to prioritize the use of those resources by the client's pins within that exclusive class. The initial priority of a pin is set by the connection request typically performed through [KsCreatePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatepin), and is usually KSPRIORITY_NORMAL, with a subclass priority of 1. A pin uses these priorities as parameters when allocating shared resources from any component managing resources. Resource allocation occurs when formats are set on pins.

If the removal of resources by a higher priority client causes the filter pin to fail, the client must be notified through the KSEVENT_CONNECTION_PRIORITY event (assuming that the client had registered for event notification of this type).

## See also

[**KSPROPERTY_CONNECTION_PRIORITY**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-connection-priority)

[KsCreatePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatepin)