## Description

The EvaluateExtendedExpression method is similar to the EvaluateExpression method except that it turns back on additional non-language functionality which a particular debug host chooses to add to its expression evaluator. For Debugging Tools for Windows, for example, this enables anonymous types, LINQ queries, module qualifiers, format specifiers, and other non-C/C++ functionality.

It is important to note that there is no guarantee that an expression which evaluates against one host via EvaluateExtendedExpression will evaluate correctly against another host which debugs the same language. Extensions in the expression evaluator are the purview of a given host. It is strongly recommended that clients utilize the EvaluateExpression method instead of the EvaluateExtendedExpression method for this exact reason. Using this method reduces the portability of the caller.

## Parameters

### `context`

The host context in which the expression evaluation occurs. If there are, for instance, memory reads of the target due to pointer dereferences, the address space in which those memory reads are made is given by this argument.

### `expression`

The expression to be evaluated. This may use host private extensions to the language syntax.

### `bindingContext`

The binding context in which symbol (variable) names will be looked up. For C++, this is semantically equivalent to the this pointer value.

### `result`

The resulting value of the expression evaluation will be returned here.

### `metadata`

Any metadata associated with the expression or result is returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IDebugHost> spHost; /* get the host */

ComPtr<IDebugHostEvaluator2> spEval;
if (SUCCEEDED(spHost.As(&spEval)))
{
    ComPtr<IModelObject> spNotepadProcesses;

    // We can use any syntax that's private to the host (not only
    // language syntax).  This is not necessarily portable from host to host
    if (SUCCEEDED(spEval->EvaluateExtendedExpression(
        USE_CURRENT_HOST_CONTEXT,
        L"@$cursession->Processes.Where(p => p.Name == \"notepad.exe\")",
        nullptr,
        &spNotepadProcesses,
        nullptr)))
    {
        // spNotepadProcesses will contain a collection of every process
        // named (exactly) "notepad.exe".  Such can be iterated with IIterableConcept.
    }
}
```

## See also

[IDebugHostEvaluator3 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostevaluator3)