# VOLUME_BITMAP_BUFFER structure

## Description

Represents the occupied and available clusters on a disk. This structure is the output buffer for the
[FSCTL_GET_VOLUME_BITMAP](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_volume_bitmap) control code.

## Members

### `StartingLcn`

Starting LCN requested as an input to the operation.

### `BitmapSize`

The number of clusters on the volume, starting from the starting LCN returned in the **StartingLcn** member of this structure. See the following Remarks section for details.

### `Buffer`

Array of bytes containing the bitmap that the operation returns. The bitmap is bitwise from bit zero of the bitmap to the end. Thus, starting at the requested cluster, the bitmap goes from bit 0 of byte 0, bit 1 of byte 0 ... bit 7 of byte 0, bit 0 of byte 1, and so on. The value 1 indicates that the cluster is allocated (in use). The value 0 indicates that the cluster is not allocated (free).

## Remarks

The **BitmapSize** member is the number of clusters on the volume starting from the starting LCN returned in the **StartingLcn** member of this structure. For example, suppose there are 0xD3F7 clusters on the volume. If you start the bitmap query at LCN 0xA007, then both the FAT and NTFS file systems will round down the returned starting LCN to LCN 0xA000. The value returned in the **BitmapSize** member will be (0xD3F7 – 0xA000), or 0x33F7.

## See also

[Defragmentation](https://learn.microsoft.com/windows/desktop/FileIO/defragmenting-files)

[FSCTL_GET_VOLUME_BITMAP](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_volume_bitmap)