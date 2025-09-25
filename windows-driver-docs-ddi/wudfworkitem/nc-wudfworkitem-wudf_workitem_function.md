# WUDF_WORKITEM_FUNCTION callback function

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

A driver's *OnWorkItem* event callback function performs the work that is associated with a specified work item.

## Parameters

### `pWorkItem` [in]

A pointer to an [IWDFWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfworkitem) interface.

## Remarks

To register an *OnWorkItem* callback function, your driver must place the callback function's address in a [WUDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/ns-wudfworkitem-_wudf_workitem_config) structure before calling [IWDFDevice3::CreateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createworkitem).

Typically, a driver's *OnWorkItem* callback function performs tasks that are specified by information that the driver stored in the context memory of a work-item object.

The driver must not call [IWDFObject::DeleteWdfObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-deletewdfobject) from the *OnWorkItem* callback function.

For more information, see [Using Work Items](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-workitems).

#### Examples

The function type is declared in *Wudfworkitem.h*, as follows.

```
typedef
VOID
WUDF_WORKITEM_FUNCTION(
    _In_
    IWDFWorkItem* pWorkItem
    );

typedef WUDF_WORKITEM_FUNCTION *PFN_WUDF_WORKITEM;
```

To define an *OnWorkItem* callback function that is named *MyWorkItem*, you must first provide a function declaration that SDV and other verification tools require, as follows:

```
WUDF_WORKITEM_FUNCTION  MyWorkItem;
```

Then, implement your callback function as follows:

```
VOID
  MyWorkItem (
   _In_
    IWDFWorkItem* pWorkItem
    )
  {…}

```

## See also

[IWDFDevice3::CreateWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createworkitem)

[IWDFObject::DeleteWdfObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-deletewdfobject)

[WUDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfworkitem/ns-wudfworkitem-_wudf_workitem_config)