# IVBGetControl::EnumControls

## Description

Enumerates the controls on the form.

**Note** The use of this method is no longer recommended because containers other than Visual Basic do not support
it.

## Parameters

### `dwOleContF` [in]

Specifies the type of OLE objects to be enumerated. This parameter can be one of the following
values enumerated by the [OLECONTF](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olecontf) enumeration.

| Value | Meaning |
| --- | --- |
| **OLECONTF_EMBEDDINGS** | Enumerates the embedded objects on the form. Include this flag to enumerate OLE controls. |
| **OLECONTF_LINKS** | Enumerates the linked objects on the form. |
| **OLECONTF_OTHER** | Enumerates all pseudo OLE objects. Include this flag to enumerate VBX controls. |
| **OLECONTF_ONLYUSER** | Enumerates only objects that the user is aware of. |
| **OLECONTF_ONLYIFRUNNING** | Enumerates only the objects that are running on the form. |

When enumerating OLE controls, it is recommended that you combine the flags
**OLECONTF_ONLYUSER**, **OLECONTF_ONLYIFRUNNING**, and
**OLECONTF_EMBEDDINGS**. To include both OLE controls and VBX controls, add the
**OLECONTF_OTHERS** flag to this list. To enumerate only VBX controls, remove the
**OLECONTF_EMBEDDINGS** flag and include the **OLECONTF_OTHERS**
flag.

### `dwWhich` [in]

Specifies the set of controls to be enumerated. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **GCW_WCH_SIBLING**<br><br>0x00000001 | Enumerates all siblings of the control. |
| **GC_WCH_CONTAINER**<br><br>0x00000002 | Enumerates all objects that are parents of your control. You cannot use the **GC_WCH_FONLYAFTER** or **GC_WCH_FONLYBEFORE** flags with this flag. |
| **GC_WCH_CONTAINED**<br><br>0x00000003 | Enumerates all objects that are children of your control. You cannot use the **GC_WCH_FONLYAFTER** or **GC_WCH_FONLYBEFORE** flags with this flag. |
| **GC_WCH_ALL**<br><br>0x00000004 | Enumerates all objects. |
| **GC_WCH_FREVERSEDIR**<br><br>0x08000000 | Enumerates and organizes controls in the reverse tab order direction. This flag can be combined with any other flag. |
| **GC_WCH_FONLYAFTER**<br><br>0x10000000 | Enumerates all controls that appear after your control in the tab order. |
| **GC_WCH_FONLYBEFORE**<br><br>0x20000000 | Enumerates all controls that appear before your control in the tab order. |
| **GC_WCH_FSELECTED**<br><br>0x40000000 | Enumerates all the controls that are currently selected. |

Use one of the flags **GC_WCH_SIBLING**, **GC_WCH_CONTAINER**,
**GC_WCH_CONTAINED**, or **GC_WCH_ALL** in combination with any of
the GC_WCH_F*xxx* flags.

In VBX code, the GC_FORM flag was passed to **VBGetControl** to obtain a pointer to
the form. In OLE control code, there is no direct replacement for this flag. Instead, pass
**GC_WHC_ALL** to
**EnumControls** and use the pointer to the
first control in the enumeration. The first control in the enumeration is always the form when using
**GC_WHC_ALL**.

### `ppenumUnk` [out]

Pointer to an enumeration of OLE objects.

## Return value

This method supports the standard return values **E_INVALIDARG**,
**E_OUTOFMEMORY**, and **E_UNEXPECTED**, as well as the
following:

## Remarks

When migrating a VBX control to an OLE control,
**EnumControls** replaces the Visual Basic
**VBGetControl**, which is no longer supported.

## See also

[IVBGetControl](https://learn.microsoft.com/windows/desktop/api/vbinterf/nn-vbinterf-ivbgetcontrol)

[OLECONTF](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-olecontf)