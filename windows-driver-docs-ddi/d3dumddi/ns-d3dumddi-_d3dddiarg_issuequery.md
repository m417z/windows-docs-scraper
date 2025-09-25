# _D3DDDIARG_ISSUEQUERY structure

## Description

The D3DDDIARG_ISSUEQUERY structure describes how to process a query that was created by the [CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery) function.

## Members

### `hQuery` [in]

The handle to the query that was created by the [CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery) function.

### `Flags` [in]

A [D3DDDI_ISSUEQUERYFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_issuequeryflags) structure that identifies the type of query to issue. The driver can ignore query requests with **Flags** set to 0.

For many query types, start query is never specified (that is, the **Begin** bit-field flag is never set for many query types). For more information about whether the **Begin** bit-field flag is set for a query type, see the **QueryType** member of the [D3DDDIARG_CREATEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createquery) structure.

## See also

[CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery)

[D3DDDI_ISSUEQUERYFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_issuequeryflags)

[IssueQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_issuequery)