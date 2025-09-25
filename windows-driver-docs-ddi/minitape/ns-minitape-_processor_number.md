# _PROCESSOR_NUMBER structure (minitape.h)

## Description

The **PROCESSOR_NUMBER** structure identifies a processor by its group number and group-relative processor number.

## Members

### `Group`

The group number. If multiprocessor system contains *n* groups, the groups are numbered from 0 to *n*-1.

### `Number`

The group-relative processor number. If a group contains *m* logical processors, the processors are numbered from 0 to *m*-1.

### `Reserved`

Reserved for future use. Initialize to zero.

## Syntax

```cpp
typedef struct _PROCESSOR_NUMBER {
  USHORT Group;
  UCHAR  Number;
  UCHAR  Reserved;
} PROCESSOR_NUMBER, *PPROCESSOR_NUMBER;
```

## Remarks

Windows 7 is the first version of Windows to support processor groups. In Windows 7, only 64-bit versions of Windows support multiple groups; 32-bit versions of Windows support only one group. If a multiprocessor system is running a 64-bit version of Windows and contains no more than 64 logical processors, Windows assigns all processors to group 0. A multiprocessor system that is running a 32-bit version of Windows can contain no more than 32 processors.

In Windows 7, the maximum number of groups in a multiprocessor system is four, but this value might change in future versions of Windows. The safest way to determine the maximum number of groups in Windows 7 or a later version of Windows is to call the [KeQueryMaximumGroupCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerymaximumgroupcount) routine. Kernel-mode drivers that call **KeQueryMaximumGroupCount** will not require code changes if the formula that is used to calculate the maximum number of groups changes in a future version of Windows.

Kernel-mode routines that use the **PROCESSOR_NUMBER** structure include [KeGetCurrentProcessorNumberEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentprocessornumberex), [KeGetProcessorIndexFromNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetprocessorindexfromnumber), [KeGetProcessorNumberFromIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetprocessornumberfromindex), and [KeQueryLogicalProcessorRelationship](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerylogicalprocessorrelationship).

## See also

[KeGetCurrentProcessorNumberEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetcurrentprocessornumberex)

[KeGetProcessorIndexFromNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetprocessorindexfromnumber)

[KeQueryLogicalProcessorRelationship](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerylogicalprocessorrelationship)

[KeQueryMaximumGroupCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerymaximumgroupcount)

[KeGetProcessorNumberFromIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kegetprocessornumberfromindex)