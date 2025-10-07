# LABELED\_BIT structure

The **LABELED\_BIT** structure defines a label BIT pair.

## Members

**BitNumber**

BIT number of the label BIT pair. Values range from 0 to 255. Set the **Bitnumber** member to the BIT used in the comparison of the property value.

**LabelOff**

String or label that is displayed when the BIT specified in **BitNumber** equals zero. For example, a possible label is "Bit OFF".

**LabelOn**

String or label that is displayed when the BIT specified in **BitNumber** equals 1. For example, a possible label is "Bit ON".

## Remarks

An array of **LABELED\_BIT** structures is used to define a set of label BIT pairs. A pointer to the array is specified in the **lpLabeledBit** member of the [SET](https://learn.microsoft.com/windows/win32/netmon2/set) structure. The pairs are used when you want to display a label based on the setting of each BIT. Typically, this type of set is used to indicate the ON or OFF value of BITs.

When a BIT set is specified, Network Monitor displays only the BITs included in the array of **SET** structures. BITs that are not in the **SET** structure are not displayed.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[SET](https://learn.microsoft.com/windows/win32/netmon2/set)

