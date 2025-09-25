# IEnumWbemClassObject::Reset

## Description

The
**IEnumWbemClassObject::Reset** method resets an enumeration sequence back to the beginning. Because CIM objects are dynamic, calling this method does not necessarily return the same list of objects that you obtained previously.

**Note** This method fails if the enumerator was originally created with the **WBEM_FLAG_FORWARD_ONLY** option.

## Return value

The
**Reset** method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

The COM-specific error codes may also be returned if the remote connection to the Windows Management is lost due to network problems.

You may see COM-specific error codes returned if network problems cause you to lose the remote connection to Windows Management.

If **WBEM_S_NO_ERROR** is not returned, you can call the COM function **GetErrorInfo** to get more information about the error.