# BCRYPT_OID_LIST structure

## Description

The **BCRYPT_OID_LIST** structure is used to contain a collection of [BCRYPT_OID](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_oid) structures. Use this structure with the [BCRYPT_HASH_OID_LIST](https://learn.microsoft.com/windows/desktop/SecCNG/cng-property-identifiers) property to retrieve the list of hashing [object identifiers](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OIDs) that have been encoded by using [Distinguished Encoding Rules](https://learn.microsoft.com/windows/desktop/SecGloss/d-gly) (DER) encoding.

## Members

### `dwOIDCount`

The number of elements in the **pOIDs** array.

### `pOIDs`

The address of an array of [BCRYPT_OID](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_oid) structures that contains OIDs.

## Remarks

The first OID in the **pOIDs** array is used to identify any hashes or signatures created by this algorithm provider. When verifying a hash or signature, all the OIDs in the array are treated as valid.

In the Microsoft Primitive Provider implementation, **dwOIDCount** is 2, so that the **pOIDs** array contains two members:

* **pOIDs[0]** contains a DER-encoded **AlgorithmIdentifier** with a **NULL** parameter.
* **pOIDs[1]** contains the DER-encoded **AlgorithmIdentifier** without a **NULL** parameter.

For example, the SHA-1 encoding would be:

* **pOIDs[0]** --> 06 05 2b 0e 03 02 1a 05 00
* **pOIDs[1]** --> 06 05 2b 0e 03 02 1a

The following snippet describes an **AlgorithmIdentifier** in [Abstract Syntax Notation One](https://learn.microsoft.com/windows/desktop/SecGloss/a-gly) (ASN.1) notation. **SEQUENCE**, **OBJECT IDENTIFIER**, and **ANY** are DER encoded. The **ANY** BLOB is **NULL**.

``` syntax
AlgorithmIdentifier ::= SEQUENCE {
   algorithm            OBJECT IDENTIFIER,
   algorithmParams      ANY
}

```

## See also

[BCRYPT_OID](https://learn.microsoft.com/windows/desktop/api/bcrypt/ns-bcrypt-bcrypt_oid)

[BCryptGetProperty](https://learn.microsoft.com/windows/desktop/api/bcrypt/nf-bcrypt-bcryptgetproperty)

[Cryptography Primitive Property Identifiers](https://learn.microsoft.com/windows/desktop/SecCNG/cng-property-identifiers)