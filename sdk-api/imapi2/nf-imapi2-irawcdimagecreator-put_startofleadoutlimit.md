# IRawCDImageCreator::put_StartOfLeadoutLimit

## Description

Sets the *StartOfLeadoutLimit* property value. This value specifies if the resulting image is required to fit on a piece of media with a **StartOfLeadout** greater than or equal to the LBA specified.

**Note** The maximum supported value for this property is 398,099, which equates to MSF 88:29:74.

## Parameters

### `value` [in]

Pointer to a **LONG** value that represents the current *StartOfLeadoutLimit*.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)

[IRawCDImageCreator::get_StartOfLeadoutLimit](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-irawcdimagecreator-get_startofleadoutlimit)