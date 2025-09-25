# NdisCurrentGroupAndProcessor function

## Description

The
**NdisCurrentGroupAndProcessor** function returns the group-relative processor number and group number of
the current processor.

## Return value

**NdisCurrentGroupAndProcessor** returns a PROCESSOR_NUMBER value that contains the group-relative
processor number and group number of the current processor.

## Remarks

NDIS drivers call the
**NdisCurrentGroupAndProcessor** function to obtain the group-relative processor number and group
number of the current processor.

The PROCESSOR_NUMBER structure contains a
**Group** member of type USHORT and a
**Number** member of type UCHAR for group and processor numbers, respectively. The group and processor
numbers are zero-based values.