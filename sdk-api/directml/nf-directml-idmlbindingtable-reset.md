# IDMLBindingTable::Reset

## Description

Resets the binding table to wrap a new range of descriptors, potentially for a different operator or
initializer. This allows dynamic reuse of the binding table.

Resetting a binding table doesn't modify any previous bindings created by the table. Because of this, it is
safe to reset the binding table immediately after supplying it to [IDMLCommandRecorder::RecordDispatch](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmlcommandrecorder-recorddispatch), even if that work has not yet completed execution on the GPU, so long as the
underlying descriptors remain valid.

See [IDMLDevice::CreateBindingTable](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-createbindingtable) for more information on the parameters supplied to this method.

## Parameters

### `desc` [in, optional]

Type: **const [DML_BINDING_TABLE_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_table_desc)***

An optional pointer to a [DML_BINDING_TABLE_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_binding_table_desc) containing the binding table parameters. This may be **nullptr**, indicating an empty binding table.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Binding in DirectML](https://learn.microsoft.com/windows/ai/directml/dml-binding)

[IDMLBindingTable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlbindingtable)