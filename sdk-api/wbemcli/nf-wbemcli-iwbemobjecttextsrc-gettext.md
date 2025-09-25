# IWbemObjectTextSrc::GetText

## Description

The **IWbemObjectTextSrc::GetText** method creates a textual representation of an
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) object; for example, an XML representation.

## Parameters

### `lFlags`

Reserved. Must be 0L.

### `pObj`

Reference to the object to be represented in text format. This parameter cannot be **NULL**.

### `uObjTextFormat`

Definition of the text format used to represent the object. For more information about valid values for this parameter, see Remarks.

#### WMI_OBJ_TEXT_CIM_DTD_2_0 (1 (0x1))

Use the DTD that corresponds to CIM DTD version 2.0.

#### WMI_OBJ_TEXT_WMI_DTD_2_0 (2 (0x2))

Use the WMI DTD that corresponds to CIM DTD version 2.0. Using this value enables WMI-specific extensions, such as embedded objects or scope.

#### WMI_OBJ_TEXT_WMI_EXT1 (3 (0x3))

Reserved for future use.

#### WMI_OBJ_TEXT_WMI_EXT2 (4 (0x4))

Reserved for future use.

#### WMI_OBJ_TEXT_WMI_EXT3 (5 (0x5))

Reserved for future use.

#### WMI_OBJ_TEXT_WMI_EXT4 (6 (0x6))

Reserved for future use.

#### WMI_OBJ_TEXT_WMI_EXT5 (7 (0x7))

Reserved for future use.

#### WMI_OBJ_TEXT_WMI_EXT6 (8 (0x8))

Reserved for future use.

#### WMI_OBJ_TEXT_WMI_EXT7 (9 (0x9))

Reserved for future use.

#### WMI_OBJ_TEXT_WMI_EXT8 (10 (0xA))

Reserved for future use.

#### WMI_OBJ_TEXT_WMI_EXT9 (11 (0xB))

Reserved for future use.

#### WMI_OBJ_TEXT_WMI_EXT10 (12 (0xC))

Reserved for future use.

#### WMI_OBJ_TEXT_LAST (13 (0xD))

Reserved for future use.

### `pCtx`

Optional. Context object for the operation. The context object can be used to specify whether certain parts of the object are represented in text; for example, whether to include qualifiers in the textual representation. The context object takes the following optional values.

#### LocalOnly (VT_BOOL)

If **TRUE**, only locally defined properties and methods are present in the resulting XML. The default is **FALSE**.

#### IncludeQualifiers (VT_BOOL)

If **TRUE**, the qualifiers of classes, instances, properties, and methods are included in the output. The default is **FALSE**.

#### PathLevel (VT_I4)

The default is 0 (zero).

Possible values are:

* 0

  A **CLASS** or **INSTANCE** element is created depending on whether the object is a class or instance.
* 1

  A **VALUE.NAMEDOBJECT** element is generated.
* 2

  A VALUE.**OBJECTWITHLOCALPATH** element is generated.
* 3

  A **VALUE.OBJECTWITHPATH** element is generated.

#### ExcludeSystemProperties (VT_BOOL)

If **TRUE**, system properties, like [__NAMESPACE](https://learn.microsoft.com/windows/desktop/WmiSdk/--namespace), are absent in the output. The default is **FALSE**.

#### IncludeClassOrigin (VT_BOOL)

If **TRUE**, the class origin attribute is set on **PROPERTY** and **METHOD** elements. The default is **FALSE**.

### `strText`

Textual representation of the object. User must free the string using [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when finished with *strText*.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

For more information, see
[Representing Objects in XML](https://learn.microsoft.com/windows/desktop/WmiSdk/representing-objects-in-xml).