# IDebugHostEvaluator2::EvaluateExpression

## Description

The EvaluateExpression method allows requests the debug host to evaluate a language (e.g.: C++) expression and return the resulting value of that expression evaluation boxed as an [IModelObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-imodelobject). This particular variant of the method only allows language constructs. Any additional functionality which is presented within the expression evaluator of the debug host that is not present in the language (e.g.: LINQ query methods) is turned off for the evaluation.

Because this method only uses things which are defined by the language being debugged, this method is portable and safe to use from host to host. A debug host which implements debugging for a particular language should evaluate an expression via this method in the same way as any other host which debugs the same language. As such, this is the preferred method for doing expression evaluation.

## Parameters

### `context`

The host context in which the expression evaluation occurs. If there are, for instance, memory reads of the target due to pointer dereferences, the address space in which those memory reads are made is given by this argument.

### `expression`

The language expression to be evaluated. This string may only contain an expression which is valid in the language being debugged. It may not contain any additional constructs which may be available in the debug host's expression evaluator.

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
ComPtr<IDebugHost> spHost;   /* get the host */
ComPtr<IModelObject> spThis; /* get some object, an example here: some native
                                object with fields m_intVal and m_intVal2 */

ComPtr<IDebugHostEvaluator2> spEval;
if (SUCCEEDED(spHost.As(&spEval)))
{
    ComPtr<IModelObject> spResult;
    ComPtr<IKeyStore> spMetadata;
    if (SUCCEEDED(spEval->EvaluateExpression(
        USE_CURRENT_HOST_CONTEXT,
        L"m_intVal + this->m_intVal2",
        spThis.Get(),
        &spResult,
        &spMetadata)))
    {
        // spResult will have the result of a language evaluation of
        // "m_intVal + this->m_intVal2" where the name binding context
        // (e.g.: *this* pointer) is spThis
        // spMetadata will have any additional metadata (e.g.: display radix, etc...)
    }
}
```

## See also

[IDebugHostEvaluator2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostevaluator2)