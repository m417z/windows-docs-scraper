# WBEM_COMPILE_STATUS_INFO structure

## Description

Describes an error for the [IMofCompiler](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-imofcompiler) interface.

## Members

### `lPhaseError`

TBD

#### 0

no error

#### 1

parsing error

#### 2

argument error

#### 3

errors occurred while storing the data.

### `hRes`

The actual error code.

### `ObjectNum`

Object that is at fault.

### `FirstLine`

First line number of the object.

### `LastLine`

Last line number of the object.

### `dwOutFlags`

Reserved.

## Remarks

The *ObjectNum*, *FirstLine*, and *LastLine* parameters only contain values for errors that relate to a particular class or instance in the file.

## See also

[CompileBuffer](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-imofcompiler-compilebuffer)

[CompileFile](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-imofcompiler-compilefile)

[CreateBMOF](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-imofcompiler-createbmof)

[IMofCompiler](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-imofcompiler)