# PCMETHOD_ITEM structure

## Description

The PCMETHOD_ITEM structure describes a method supported by a filter, pin, or node.

## Members

### `Set`

Specifies the method set. This member is a pointer to a GUID that uniquely identifies the method set.

### `Id`

Specifies the method ID. This member identifies a method item in the method set. If the method set contains *n* items, valid method IDs are integers in the range 0 to *n*-1.

### `Flags`

Specifies the type of parameter passing and memory access that a method uses. This member can be set to the bitwise OR of one or more of the flag bits in the following table.

| Flag bit | Meaning |
| --- | --- |
| PCMETHOD_ITEM_FLAG_MODIFY | The method reads from and writes to the parameter buffer. |
| PCMETHOD_ITEM_FLAG_NONE | The method does not use the parameter buffer. |
| PCMETHOD_ITEM_FLAG_READ | The method reads from the parameter buffer. |
| PCMETHOD_ITEM_FLAG_SOURCE | The method probes and locks memory pages before attempting memory access. |
| PCMETHOD_ITEM_FLAG_WRITE | The method writes to the parameter buffer. |

### `Handler`

Pointer to the method-handler routine. This member is a function pointer of type PCPFNMETHOD_HANDLER, which is defined as follows:

```
  typedef NTSTATUS (*PCPFNMETHOD_HANDLER)
  (
      IN PPCMETHOD_REQUEST  MethodRequest
  );
```

When calling the **Handler** routine, the caller passes in a single call parameter, which is a pointer to a structure of type [PCMETHOD_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcmethod_request).

## Remarks

The WDM audio subsystem does not currently support methods on either filter instances or pin instances. This restriction also precludes support for methods on nodes.

The [PCAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcautomation_table) structure contains a pointer to an array of PCMETHOD_ITEM structures.

## See also

[PCMETHOD_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-_pcmethod_request)