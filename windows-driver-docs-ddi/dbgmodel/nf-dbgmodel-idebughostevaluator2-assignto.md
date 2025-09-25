# IDebugHostEvaluator2::AssignTo

## Description

The AssignTo method performs assignment according to the semantics of the language being debugged.

## Parameters

### `assignmentReference`

A reference to the thing being assigned. While this can be either a model based reference (e.g.: an ObjectTargetObjectReference) or a language reference (e.g.: a C++ &), it must be some type of reference (an LVALUE).

### `assignmentValue`

The value being assigned to what is referenced via the assignmentReference argument. Note that this value may be coerced or converted according to language rules before being assigned.

### `assignmentResult`

The result of assignment, if successful. If not, optionally, an extended error object indicating why the assignment failed. Note that result of assignment in this case is what the language defines as the result of an assignment operation. For C++, this would be a language reference to the thing assigned.

### `assignmentMetadata`

Any optional metadata associated with the assignment result is returned here.

## Return value

This method returns HRESULT which indicates success or failure.

## Remarks

**Code Sample**

```cpp
ComPtr<IDebugHost> spHost;           /* get the host */
ComPtr<IDataModelManager> spManager; /* get the data model manager */
ComPtr<IModelObject> spObject;       /* get an object; for an example - consider a
                                        'class MyClass' with an integer value
                                        m_intVal */

ComPtr<IDebugHostEvaluator2> spEval2;
if (SUCCEEDED(spHost.As(&spEval2)))
{
    // Get a reference to the m_intVal field
    ComPtr<IModelObject> spIntValRef;
    if (SUCCEEDED(spObject->GetRawReference(SymbolField,
                                            L"m_intVal",
                                            RawSearchNone,
                                            &spIntValRef)))
    {
        // Box some value we want to assign.
        VARIANT vtVal;
        vtVal.vt = VT_UI8;
        vtVal.ullVal = 123456;

        ComPtr<IModelObject> spAssignmentValue;
        if (SUCCEEDED(spManager->CreateIntrinsicObject(ObjectIntrinsic,
                                                       &vtVal,
                                                       &spAssignmentValue)))
        {
            ComPtr<IModelObject> spAssignmentResult;
            if (SUCCEEDED(spEval2->AssignTo(spIntValRef.Get(),
                                            spAssignmentValue.Get(),
                                            &spAssignmentResult,
                                            nullptr)))
            {
                // The (unsigned __int64)123456 was assigned to m_intVal with
                // the set of coercions defined by the language (C++)
                // spAssignmentResult has the language meaning of operator=()
                // in this case.  This would be a MyClass&.
            }
        }
    }
}
```

## See also

[IDebugHostEvaluator2 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idebughostevaluator2)