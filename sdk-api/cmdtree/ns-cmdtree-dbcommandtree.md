# DBCOMMANDTREE structure

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **DBCOMMANDTREE** structure is the primary data structure used to represent any node in an OLE DB command tree, as described in the [Data Manipulation Operators](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/data-manipulation-operators) and Data Definition Operators section of this reference. This structure is used for each data manipulation language (DML) or data definition language (DDL) node in an OLE DB command tree.

## Members

### `op`

Operator identifier (2 bytes)

A value of type [DBCOMMANDOP](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandop) from the [DBCOMMANDOPENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/ne-cmdtree-dbcommandopenum) enumeration. It specifies an operator from the [Data Manipulation Operators](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/data-manipulation-operators) or the Data Definition Operators that defines the operation to take place on the associated field.

### `wKind`

Discriminator for the following union (2 bytes)

A value of type [DBVALUEKIND](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbvaluekind) from the [DBVALUEKINDENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/ne-cmdtree-dbvaluekindenum) enumerated type. It defines the data type of the associated union member so that the command processor knows how to interpret it.

### `pctFirstChild`

Pointer to first child (4 bytes)

A pointer to the **DBCOMMANDTREE** structure that represents the first child of this node of the command tree.

### `pctNextSibling`

Pointer to sibling (4 bytes)

A pointer to the **DBCOMMANDTREE** structure that represents the next child of this node of the command tree.

### `value`

Union directly represents fields that fit within 8 bytes. Comments list DBVALUEKIND and DBTYPE corresponding to each field.

A union to hold the value for every data type supported by this OLE DB provider. For any union member data type that holds 8 bytes or less, the value itself is stored here. Otherwise, **llvalue** is a **pwszValue** member, a pointer to the data.

A **pwszValue** member is a string; its interpretation is left to the provider. In other words, the consumer must understand the provider's method of name resolution. For command components "passed through" to another provider, it is left to the receiving provider to interpret the string.

The **pMoniker** member is used for unresolved linked objects, in particular tables and functions.

The **pRowset** member is used to reference a currently open rowset as input for a command. Most providers will fail if an [IPersist](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersist) method is invoked while the command tree refers to an open rowset.

The **pCommand** member references another command object as input for a command. Most providers will fail if an [IPersist](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersist) method is invoked while the command tree refers to a command object that does not support monikers.

### `value.llValue`

DBVALUEKIND_I8 (DBTYPE_I8)

### `value.ullValue`

DBVALUEKIND_UI8 (DBTYPE_UI8)

### `value.fValue`

DBVALUEKIND_BOOL (DBTYPE_BOOL)

### `value.uchValue`

DBVALUEKIND_UI1 (DBTYPE_UI1)

### `value.schValue`

DBVALUEKIND_I1 (DBTYPE_I1)

### `value.usValue`

DBVALUEKIND_UI2 (DBTYPE_UI2)

### `value.sValue`

DBVALUEKIND_I2 (DBTYPE_I2)

### `value.pwszValue`

DBVALUEKIND_WSTR (DBTYPE_WSTR)

### `value.lValue`

DBVALUEKIND_I4 (DBTYPE_I4)

### `value.ulValue`

DBVALUEKIND_UI4 (DBTYPE_UI4)

### `value.flValue`

DBVALUEKIND_R4 (DBTYPE_R4)

### `value.dblValue`

DBVALUEKIND_R8 (DBTYPE_R8)

### `value.cyValue`

DBVALUEKIND_CY (DBTYPE_CY)

### `value.dateValue`

DBVALUEKIND_DATE (DBTYPE_DATE)

### `value.dbdateValue`

DBVALUEKIND_DBDATE (DBTYPE_DBDATE)

### `value.dbtimeValue`

DBVALUEKIND_DBTIME (DBTYPE_DBTIME)

### `value.scodeValue`

DBVALUEKIND_ERROR (DBTYPE_ERROR)

### `value.pbstrValue`

DBVALUEKIND_BSTR (DBTYPE_BSTR)

### `value.pCommand`

DBVALUEKIND_COMMAND (DBTYPE_IUNKNOWN)

### `value.pDispatch`

DBVALUEKIND_IDISPATCH (DBTYPE_IDISPATCH)

### `value.pMoniker`

DBVALUEKIND_MONIKER (DBTYPE_MONIKER)

### `value.pRowset`

DBVALUEKIND_ROWSET (DBTYPE_ROWSET)

### `value.pUnknown`

DBVALUEKIND_IUNKNOWN (DBTYPE_IUNKNOWN)

### `value.pdbbygdValue`

DBVALUEKIND_BYGUID

### `value.pcoldescValue`

DBVALUEKIND_COLDESC

### `value.pdbidValue`

DBVALUEKIND_ID

### `value.pdblikeValue`

DBVALUEKIND_LIKE

### `value.pdbcntntValue`

DBVALUEKIND_CONTENT

### `value.pdbcntntscpValue`

DBVALUEKIND_CONTENTSCOPE

### `value.pdbcntnttblValue`

DBVALUEKIND_CONTENTTABLE

### `value.pdbcntntvcValue`

DBVALUEKIND_CONTENTVECTOR

### `value.pdbcntntproxValue`

DBVALUEKIND_CONTENTPROXIMITY

### `value.pdbgrpinfValue`

DBVALUEKIND_GROUPINFO

### `value.pdbparamValue`

DBVALUEKIND_PARAMETER

### `value.pdbpropValue`

DBVALUEKIND_PROPERTY

### `value.pdbstfncValue`

DBVALUEKIND_SETFUNC

### `value.pdbsrtinfValue`

DBVALUEKIND_SORTINFO

### `value.pdbtxtValue`

DBVALUEKIND_TEXT

### `value.pdbvectorValue`

DBVALUEKIND_VECTOR | *

### `value.parrayValue`

DBVALUEKIND_ARRAY | *

### `value.pvarValue`

DBVALUEKIND_VARIANT (DBTYPE_VARIANT)

### `value.pGuid`

DBVALUEKIND_GUID (DBTYPE_GUID)

### `value.pbValue`

DBVALUEKIND_BYTES (DBTYPE_BYTES)

### `value.pzValue`

DBVALUEKIND_STR (DBTYPE_STR)

### `value.pdbnValue`

DBVALUEKIND_NUMERIC (DBTYPE_NUMERIC)

### `value.pdbtsValue`

DBVALUEKIND_DBTIMESTAMP (DBTYPE_DBTIMESTAMP)

### `value.pvValue`

a generic DBVALUEKIND_BYREF

### `value.pdbprobValue`

DBVALUEKIND_PROBABILISTIC

### `value.pdbreldocValue`

DBVALUEKIND_RELEVANTDOCUMENT

### `hrError`

Error indicator, details in Extended Error info (4 bytes)

## Remarks

Many operations create a binding environment. For example, a DBOP_select operation has two inputs — a table and a Boolean predicate. (For more information on this operation, see [Operators with Two Variants for Ordered and Non-Ordered Tables](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/operators-with-two-variants-for-ordered-and-non-ordered-tables).) By virtue of the "select" operation, the table becomes the binding environment for the predicate. That means that the predicate may freely reference column names defined in the table. Note that not all bindings must come from the nearest table operation. For example, there might be multiple table operations within an "exist" expression, and any predicate may reference a column defined outside the "exist" expression. (In SQL, this is called a "correlated subquery.")

The typical size of a **DBCOMMANDTREE** structure for a node is 24 bytes. However, operators may store some specific information in the value field of the node. For programming convenience, the union field includes branches representing some common types that can fit within 8 bytes. Variable-length types are referenced via a pointer to the corresponding structure (such as [DBTEXT](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbtext)). The discriminator for the union is of type **WORD** rather than [DBVALUEKIND](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbvaluekind) so that it is possible to store node values such as DBVALUEKIND_VECTOR | DBVALUEKIND_GUID, DBVALUEKIND_BYREF | DBVALUEKIND_UI4, or DBVALUEKIND_SAFEARRAY | DBVALUEKIND_I4.