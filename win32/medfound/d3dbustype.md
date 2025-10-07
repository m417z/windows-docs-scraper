# D3DBUSTYPE enumeration

Specifies the type of I/O bus used by the graphics adapter.

## Constants

**D3DBUSTYPE\_OTHER**

Indicates a type of bus other than the types listed here.

**D3DBUSTYPE\_PCI**

PCI bus.

**D3DBUSTYPE\_PCIX**

PCI-X bus.

**D3DBUSTYPE\_PCIEXPRESS**

PCI Express bus.

**D3DBUSTYPE\_AGP**

Accelerated Graphics Port (AGP) bus.

**D3DBUSIMPL\_MODIFIER\_INSIDE\_OF\_CHIPSET**

The implementation for the graphics adapter is in a motherboard chipset's north bridge. This flag implies that data never goes over an expansion bus (such as PCI or AGP) when it is transferred from main memory to the graphics adapter.

**D3DBUSIMPL\_MODIFIER\_TRACKS\_ON\_MOTHER\_BOARD\_TO\_CHIP**

Indicates that the graphics adapter is connected to a motherboard chipset's north bridge by tracks on the motherboard and all of the graphics adapter's chips are soldered to the motherboard. This flag implies that data never goes over an expansion bus (such as PCI or AGP) when it is transferred from main memory to the graphics adapter.

**D3DBUSIMPL\_MODIFIER\_TRACKS\_ON\_MOTHER\_BOARD\_TO\_SOCKET**

The graphics adapter is connected to a motherboard chipset's north bridge by tracks on the motherboard, and all of the graphics adapter's chips are connected through sockets to the motherboard.

**D3DBUSIMPL\_MODIFIER\_DAUGHTER\_BOARD\_CONNECTOR**

The graphics adapter is connected to the motherboard through a daughterboard connector.

**D3DBUSIMPL\_MODIFIER\_DAUGHTER\_BOARD\_CONNECTOR\_INSIDE\_OF\_NUAE**

The graphics adapter is connected to the motherboard through a daughterboard connector, and the graphics adapter is inside an enclosure that is not user accessible.

**D3DBUSIMPL\_MODIFIER\_NON\_STANDARD**

One of the D3DBUSIMPL\_MODIFIER\_MODIFIER\_Xxx flags is set.

## Remarks

As many as three flags can be set. Flags in the range 0x00 through 0x04 (**D3DBUSTYPE\_Xxx**) provide the basic bus type. Flags in the range 0x10000 through 0x50000 (**D3DBUSIMPL\_MODIFIER\_Xxx**) modify the basic description. The driver sets one bus-type flag, and can set zero or one modifier flag. If the driver sets a modifier flag, it also sets the **D3DBUSIMPL\_MODIFIER\_NON\_STANDARD** flag. Flags are combined with a bitwise **OR**.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | D3d9types.h (include D3d9.h) |

## See also

[Direct3D Video Enumerations](https://learn.microsoft.com/windows/win32/medfound/direct3d-video-enumerations)

