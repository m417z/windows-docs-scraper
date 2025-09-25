# CRYPT_ALGORITHM_IDENTIFIER structure

## Description

The **CRYPT_ALGORITHM_IDENTIFIER** structure specifies an algorithm used to encrypt a [private key](https://learn.microsoft.com/windows/win32/SecGloss/p-gly). The structure includes the [object identifier](https://learn.microsoft.com/windows/win32/SecGloss/o-gly) (OID) of the algorithm and any needed parameters for that algorithm. The parameters contained in its [CRYPT_OBJID_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) are encoded.

## Members

### `pszObjId`

An OID of an algorithm. This member can be one of the following values. This list is only representative. New algorithms are being defined by various users.

| Value | Meaning |
| --- | --- |
| **szOID_RSA**<br><br>"1.2.840.113549" | Root object identifier for the RSA asymmetric encryption algorithm family. RSA stands for Ron Rivest, Adi Shamir and Leonard Adleman, the mathematicians who invented the algorithm. This is a popular asymmetric algorithm that can be used for encryption or signing. |
| **szOID_PKCS**<br><br>"1.2.840.113549.1" | Root object identifier for the PKCS (Public Key Cryptography Standards) group of standards that define public key or asymmetric cryptography. |
| **szOID_RSA_HASH**<br><br>"1.2.840.113549.2" | RSA signing (encryption) algorithm that uses a hashing algorithm to hash the content before signing it. |
| **szOID_RSA_ENCRYPT**<br><br>"1.2.840.113549.3" | RSA encryption algorithm. |
| **szOID_PKCS_1**<br><br>"1.2.840.113549.1.1" | PKCS#1 is the first Public Key Cryptography Standard (PKCS) published by RSA Laboratories. The PKCS#1 standard defines the properties of encryption and decryption employed by the RSA algorithm. |
| **szOID_PKCS_2**<br><br>"1.2.840.113549.1.2" | PKCS#2 was a Public Key Cryptography Standard (PKCS) that dealt with RSA encryption of message digests. It has been merged into PKCS#1. |
| **szOID_PKCS_3**<br><br>"1.2.840.113549.1.3" | PKCS#3 is a Public Key Cryptography Standard (PKCS) that defines the Diffie-Hellman key agreement protocol. |
| **szOID_PKCS_4**<br><br>"1.2.840.113549.1.4" | PKCS#4 was a Public Key Cryptography Standard (PKCS) that defined the RSA key syntax. It has been merged into PKCS#1. |
| **szOID_PKCS_5**<br><br>"1.2.840.113549.1.5" | PKCS#5 is a Public Key Cryptography Standard (PKCS) that provides recommendations for the implementation of password-based cryptography. It covers key derivation functions, encryption schemes, message-authentication schemes, and ASN.1 syntax structure. |
| **szOID_PKCS_6**<br><br>"1.2.840.113549.1.6" | PKCS#6 is a Public Key Cryptography Standard (PKCS) that describes the syntax for extended certificate information, a set of attributes that provides additional information about the entity whose public key is certified in the X.509 certificate. |
| **szOID_PKCS_7**<br><br>"1.2.840.113549.1.7" | PKCS#7 is a Public Key Cryptography Standard (PKCS) that describes the general types of content to which cryptography can be applied. This includes data, signed data, enveloped data, signed-and-enveloped data, digested data, and encrypted data. |
| **szOID_PKCS_8**<br><br>"1.2.840.113549.1.8" | PKCS#8 is a Public Key Cryptography Standard (PKCS) that defines the syntax for private key information in the **PrivateKeyInfo** ASN.1 type. |
| **szOID_PKCS_9**<br><br>"1.2.840.113549.1.9" | PKCS#8 is a Public Key Cryptography Standard (PKCS) that defines attribute types for use in PKCS#6 extended certificates, PKCS#7 digitally signed messages, PKCS#8 private-key information, and PKCS#10 certificate-signing requests. |
| **szOID_PKCS_10**<br><br>"1.2.840.113549.1.10" | PKCS#10 is a Public Key Cryptography Standard (PKCS) that describes the certificate request syntax. |
| **szOID_PKCS_12**<br><br>"1.2.840.113549.1.12" | PKCS#12 is a Public Key Cryptography Standard (PKCS) that describes the personal information exchange (PFX) format used to transfer personal identity information such as private keys and certificates. |
| **szOID_RSA_MD2**<br><br>"1.2.840.113549.2.2" | RSA algorithm coupled with an MD2 message digest algorithm that hashes the message contents before signing. |
| **szOID_RSA_MD4**<br><br>"1.2.840.113549.2.4" | RSA algorithm coupled with an MD4 message digest algorithm that hashes the message contents before signing. |
| **szOID_RSA_MD5**<br><br>"1.2.840.113549.2.5" | RSA algorithm coupled with an MD5 message digest algorithm that hashes the message contents before signing. |
| **szOID_RSA_RSA**<br><br>"1.2.840.113549.1.1.1" | RSA is used to both encrypt and sign content. |
| **szOID_RSA_MD2RSA**<br><br>"1.2.840.113549.1.1.2" | RSA is used to encrypt the content and to sign the content hash created by using the MD2 message digest algorithm. |
| **szOID_RSA_MD4RSA**<br><br>"1.2.840.113549.1.1.3" | RSA is used to encrypt the content and to sign the content hash created by using the MD4 message digest algorithm. |
| **szOID_RSA_MD5RSA**<br><br>"1.2.840.113549.1.1.4" | RSA is used to encrypt the content and to sign the content hash created by using the MD5 message digest algorithm. |
| **szOID_RSA_SHA1RSA**<br><br>"1.2.840.113549.1.1.5" | RSA is used to encrypt the content and to sign the content hash created by using the Secure Hashing Algorithm (SHA) algorithm. |
| **szOID_RSA_SETOAEP_RSA**<br><br>"1.2.840.113549.1.1.6" | RSA that uses Optimal Asymmetric Encryption Padding (OAEP) encoding. |
| **szOID_RSAES_OAEP**<br><br>"1.2.840.113549.1.1.7" | Public-key encryption scheme combining Optimal Asymmetric Encryption Padding (OAEP) with the RSAEP encryption primitive. RSAES-OAEP takes a plaintext as input, transforms it into an encoded message by using OAEP and applies RSAEP to the result using the RSA public key. |
| **szOID_RSA_MGF1**<br><br>"1.2.840.113549.1.1.8" | RSA algorithm that uses the mask generator function (MGF1) |
| **szOID_RSA_PSPECIFIED**<br><br>"1.2.840.113549.1.1.9" | RSA algorithm. |
| **szOID_RSA_SSA_PSS**<br><br>"1.2.840.113549.1.1.10" | RSA algorithm that uses the probabilistic signature scheme (PSS). |
| **szOID_RSA_SHA256RSA**<br><br>1.2.840.113549.1.1.11 | RSA is used to encrypt the content and to sign the hash created by using the Secure Hashing Algorithm 256 (SHA256) algorithm. |
| **szOID_RSA_SHA384RSA**<br><br>1.2.840.113549.1.1.12 | RSA is used to encrypt the content and to sign the hash created by using the Secure Hashing Algorithm 384 (SHA384) algorithm. |
| **szOID_RSA_SHA512RSA**<br><br>1.2.840.113549.1.1.13 | RSA is used to encrypt the content and to sign the hash created by using the Secure Hashing Algorithm 512 (SHA512) algorithm. |
| **szOID_RSA_DH**<br><br>"1.2.840.113549.1.3.1" | RSA algorithm combined with the Diffie-Hellman key exchange algorithm. |
| **szOID_RSA_data**<br><br>"1.2.840.113549.1.7.1" | RSA applied over the PKCS#7 ASN.1 **Data** type. |
| **szOID_RSA_signedData**<br><br>"1.2.840.113549.1.7.2" | RSA applied over the PKCS#7 ASN.1 **SignedData** type. |
| **szOID_RSA_envelopedData**<br><br>"1.2.840.113549.1.7.3" | RSA applied over the PKCS#7 ASN.1 **EnvelopedData** type. |
| **szOID_RSA_signEnvData**<br><br>"1.2.840.113549.1.7.4" | RSA applied over the PKCS#7 ASN.1 **SignedAndEnvelopedData** type. |
| **szOID_RSA_digestedData**<br><br>"1.2.840.113549.1.7.5" | RSA applied over the PKCS#7 ASN.1 **DigestedData** type. |
| **szOID_RSA_hashedData**<br><br>"1.2.840.113549.1.7.5" | RSA algorithm applied to hashed data. |
| **szOID_RSA_encryptedData**<br><br>"1.2.840.113549.1.7.6" | RSA applied over the PKCS#7 ASN.1 **EncryptedData** type. |
| **szOID_RSA_emailAddr**<br><br>"1.2.840.113549.1.9.1" | RSA applied to the to an ASN.1 email address. |
| **szOID_RSA_unstructName**<br><br>"1.2.840.113549.1.9.2" | RSA applied to the an ASN.1 unstructured name. |
| **szOID_RSA_contentType**<br><br>"1.2.840.113549.1.9.3" | RSA applied to the ASN.1 content type value. |
| **szOID_RSA_messageDigest**<br><br>"1.2.840.113549.1.9.4" | RSA applied to a message digest. |
| **szOID_RSA_signingTime**<br><br>"1.2.840.113549.1.9.5" | RSA applied to the signing date and time value |
| **szOID_RSA_counterSign**<br><br>"1.2.840.113549.1.9.6" | RSA applied to the counter signature. |
| **szOID_RSA_challengePwd**<br><br>"1.2.840.113549.1.9.7" | RSA applied to a challenge password. |
| **szOID_RSA_unstructAddr**<br><br>"1.2.840.113549.1.9.8" | RSA applied to an unstructured address. |
| **szOID_RSA_extCertAttrs**<br><br>"1.2.840.113549.1.9.9" | RSA applied to the certificate attributes. |
| **szOID_RSA_certExtensions**<br><br>"1.2.840.113549.1.9.14" | RSA applied to certificate extensions. |
| **szOID_RSA_SMIMECapabilities**<br><br>"1.2.840.113549.1.9.15" | RSA applied to the Multipurpose Internet Mail Extensions (MIME) |
| **szOID_RSA_preferSignedData**<br><br>"1.2.840.113549.1.9.15.1" | RSA applied to the SMIME **preferSignedData** capability preference. |
| **szOID_TIMESTAMP_TOKEN**<br><br>"1.2.840.113549.1.9.16.1.4" | Timestamp object identifier. |
| **szOID_RFC3161_counterSign**<br><br>"1.3.6.1.4.1.311.3.3.1" | Counter signature of a signature. |
| **szOID_RSA_SMIMEalg**<br><br>"1.2.840.113549.1.9.16.3" | RSA applied to the Multipurpose Internet Mail Extensions (MIME) algorithm. SMIME reports the decryption capabilities of an email recipient to an email sender so that the sender can choose the most secure algorithm supported by both parties. |
| **szOID_RSA_SMIMEalgESDH**<br><br>"1.2.840.113549.1.9.16.3.5" | RSA applied to the specified SMIME ESDH algorithm. |
| **szOID_RSA_SMIMEalgCMS3DESwrap**<br><br>"1.2.840.113549.1.9.16.3.6" | RSA applied to the SMIME algorithm. Triple DES is used for key wrapping. |
| **szOID_RSA_SMIMEalgCMSRC2wrap**<br><br>"1.2.840.113549.1.9.16.3.7" | RSA applied to the SMIME algorithm. RC2 is used for key wrapping. |
| **szOID_RSA_RC2CBC**<br><br>"1.2.840.113549.3.2" | RSA that uses the Rivest Cipher (RC2) block cipher algorithm coupled with a cipher-block chaining mode of operation. |
| **szOID_RSA_RC4**<br><br>"1.2.840.113549.3.4" | RSA that uses the Rivest Cipher (RC4) block cipher algorithm coupled with a cipher-block chaining mode of operation. |
| **szOID_RSA_DES_EDE3_CBC**<br><br>"1.2.840.113549.3.7" | RSA that uses the triple Data Encryption Standard (DES) algorithm coupled with a cipher-block chaining mode of operation. The encryption operation is performed as encrypt-decrypt-encrypt. |
| **szOID_RSA_RC5_CBCPad**<br><br>"1.2.840.113549.3.9" | RSA that uses the Rivest Cipher (RC5) block cipher algorithm coupled with a cipher-block chaining pad mode of operation |
| **szOID_ANSI_x942**<br><br>"1.2.840.10046" | Root object identifier for the ANSI X942 standard. |
| **szOID_ANSI_x942_DH**<br><br>"1.2.840.10046.2.1" | Diffie-Hellman Key Exchange Algorithm. |
| **szOID_X957**<br><br>"1.2.840.10040" | Root object identifier for the X957 standard. |
| **szOID_X957_DSA**<br><br>"1.2.840.10040.4.1" | Digital Signature Algorithm (DSA). |
| **szOID_X957_SHA1DSA**<br><br>"1.2.840.10040.4.3" | Digital Signature Algorithm (DSA) coupled with the Secure Hashing Algorithm (SHA) algorithm. |
| **szOID_ECC_PUBLIC_KEY**<br><br>"1.2.840.10045.2.1" | Elliptic curve public key cryptography. |
| **szOID_ECC_CURVE_P256**<br><br>"1.2.840.10045.3.1.7" | 256 bit elliptic curve. |
| **szOID_ECC_CURVE_P384**<br><br>"1.3.132.0.34" | 384 bit elliptic curve. |
| **szOID_ECC_CURVE_P521**<br><br>"1.3.132.0.35" | 512 bit elliptic curve. |
| **szOID_ECDSA_SHA1**<br><br>"1.2.840.10045.4.1" | Elliptic curve Digital Signature Algorithm (DSA) coupled with the Secure Hashing Algorithm (SHA) algorithm. |
| **szOID_ECDSA_SPECIFIED**<br><br>"1.2.840.10045.4.3" | Elliptic curve Digital Signature Algorithm (DSA). |
| **szOID_ECDSA_SHA256**<br><br>"1.2.840.10045.4.3.2" | Elliptic curve Digital Signature Algorithm (DSA) coupled with the Secure Hashing Algorithm (SHA256) algorithm. |
| **szOID_ECDSA_SHA384**<br><br>"1.2.840.10045.4.3.3" | Elliptic curve Digital Signature Algorithm (DSA) coupled with the Secure Hashing Algorithm (SHA384) algorithm. |
| **szOID_ECDSA_SHA512**<br><br>"1.2.840.10045.4.3.4" | Elliptic curve Digital Signature Algorithm (DSA) coupled with the Secure Hashing Algorithm (SHA512) algorithm. |
| **szOID_NO_HASH**<br><br>"1.3.6.1.4.1.311.73.1" | An OID that indicates that no hash algorithm is used. |
| **szOID_NIST_AES128_CBC**<br><br>"2.16.840.1.101.3.4.1.2" | 128 bit Advanced Encryption Standard (AES) algorithm with cipher-block chaining mode of operation. |
| **szOID_NIST_AES192_CBC**<br><br>"2.16.840.1.101.3.4.1.22" | 192 bit Advanced Encryption Standard (AES) algorithm with cipher-block chaining mode of operation. |
| **szOID_NIST_AES256_CBC**<br><br>"2.16.840.1.101.3.4.1.42" | 256 bit Advanced Encryption Standard (AES) algorithm with cipher-block chaining mode of operation. |
| **szOID_NIST_AES128_WRAP**<br><br>"2.16.840.1.101.3.4.1.5" | 128 bit Advanced Encryption Standard (AES) algorithm used for key wrapping. |
| **szOID_NIST_AES192_WRAP**<br><br>"2.16.840.1.101.3.4.1.25" | 192 bit Advanced Encryption Standard (AES) algorithm used for key wrapping. |
| **szOID_NIST_AES256_WRAP**<br><br>"2.16.840.1.101.3.4.1.45" | 256 bit Advanced Encryption Standard (AES) algorithm used for key wrapping. |
| **szOID_DATA STRUCTURE**<br><br>"1.2.840.10040.4.3" | Unspecified data structure. |
| **szOID_DH_SINGLE_PASS_STDDH_SHA1_KDF**<br><br>"1.3.133.16.840.63.0.2" | Single pass SHA1 key derivation. |
| **szOID_DH_SINGLE_PASS_STDDH_SHA256_KDF**<br><br>"1.3.132.1.11.1" | Single pass SHA256 key derivation.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This OID is not supported. |
| **szOID_DH_SINGLE_PASS_STDDH_SHA384_KDF**<br><br>"1.3.132.1.11.2" | Single pass SHA384 key derivation.<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This OID is not supported. |
| **szOID_DS**<br><br>"2.5" | Enveloped signature. |
| **szOID_DSALG**<br><br>"2.5.8" | Enveloped digital signature algorithm. |
| **szOID_DSALG_CRPT**<br><br>"2.5.8.1" | Digital signature algorithm applied to encrypted content. |
| **szOID_DSALG_HASH**<br><br>"2.5.8.2" | Digital signature algorithm applied to hashed content. |
| **szOID_DSALG_SIGN**<br><br>"2.5.8.3" | Digital signature algorithm applied to a signature. |
| **szOID_DSALG_RSA**<br><br>"2.5.8.1.1" | Enveloped digital signature algorithm applied to RSA encrypted or signed content. |
| **szOID_OIW**<br><br>"1.3.14" | NIST OSE Implementors' Workshop (OIW) root object identifier. |
| **szOID_OIWSEC**<br><br>"1.3.14.3.2" | NIST OSE Implementors' Workshop (OIW) Security standard root object identifier. |
| **szOID_OIWSEC_md4RSA**<br><br>"1.3.14.3.2.2" | NIST OSE Implementors' Workshop (OIW) Security RSA algorithm applied to a hash created by using the Message Digest (MD4) algorithm. |
| **szOID_OIWSEC_md5RSA**<br><br>"1.3.14.3.2.3" | NIST OSE Implementors' Workshop (OIW) Security RSA algorithm applied to a hash created by using the Message Digest (MD5) algorithm. |
| **szOID_OIWSEC_md4RSA2**<br><br>"1.3.14.3.2.4" | NIST OSE Implementors' Workshop (OIW) Security RSA2 algorithm applied to a hash created by using the Message Digest (MD5) algorithm. |
| **szOID_OIWSEC_desECB**<br><br>"1.3.14.3.2.6" | NIST OSE Implementors' Workshop (OIW) Security Data Encryption Standard (DES) algorithm coupled with a electronic codebook mode of operation. |
| **szOID_OIWSEC_desCBC**<br><br>"1.3.14.3.2.7" | NIST OSE Implementors' Workshop (OIW) Security Data Encryption Standard (DES) algorithm coupled with a cipher-block chaining mode of operation. |
| **szOID_OIWSEC_desOFB**<br><br>"1.3.14.3.2.8" | Data Encryption Standard (DES) algorithm coupled with a cipher-block chaining mode of operation. |
| **szOID_OIWSEC_desCFB**<br><br>"1.3.14.3.2.9" | NIST OSE Implementors' Workshop (OIW) Security Data Encryption Standard (DES) algorithm coupled with a output feedback mode of operation. |
| **szOID_OIWSEC_desMAC**<br><br>"1.3.14.3.2.10" | NIST OSE Implementors' Workshop (OIW) Security Data Encryption Standard (DES) algorithm coupled with a message authentication code (MAC) that hashes both the pre-image and the key. |
| **szOID_OIWSEC_rsaSign**<br><br>"1.3.14.3.2.11" | NIST OSE Implementors' Workshop (OIW) Security RSA signature algorithm. |
| **szOID_OIWSEC_dsa**<br><br>"1.3.14.3.2.12" | NIST OSE Implementors' Workshop (OIW) Security Digital Signature Algorithm (DSA). |
| **szOID_OIWSEC_shaDSA**<br><br>"1.3.14.3.2.13" | NIST OSE Implementors' Workshop (OIW) Security Digital Signature Algorithm (DSA) that uses the Secure Hashing Algorithm (SHA) to hash the message contents. |
| **szOID_OIWSEC_mdc2RSA**<br><br>"1.3.14.3.2.14" | NIST OSE Implementors' Workshop (OIW) Security RSA algorithm that uses the Modification Detection Code 2 (MDC2) or Meyer-Schilling hash function. |
| **szOID_OIWSEC_shaRSA**<br><br>"1.3.14.3.2.15" | NIST OSE Implementors' Workshop (OIW) Security RSA algorithm coupled with the Secure Hashing Algorithm (SHA). |
| **szOID_OIWSEC_dhCommMod**<br><br>"1.3.14.3.2.16" | NIST OSE Implementors' Workshop (OIW) Security Diffie-Hellman key exchange algorithm. |
| **szOID_OIWSEC_desEDE**<br><br>"1.3.14.3.2.17" | NIST OSE Implementors' Workshop (OIW) Security Data Encryption Standard (DES) algorithm coupled with the encrypt-decrypt-encrypt (EDE) multiple encryption mode of operation. |
| **szOID_OIWSEC_sha**<br><br>"1.3.14.3.2.18" | NIST OSE Implementors' Workshop (OIW) Security Secure Hashing Algorithm (SHA). |
| **szOID_OIWSEC_mdc2**<br><br>"1.3.14.3.2.19" | NIST OSE Implementors' Workshop (OIW) Security Modification Detection Code 2 (MDC2) or Meyer-Schilling hash function. |
| **szOID_OIWSEC_dsaComm**<br><br>"1.3.14.3.2.20" | NIST OSE Implementors' Workshop (OIW) Security Digital Signature Algorithm (DSA). |
| **szOID_OIWSEC_dsaCommSHA**<br><br>"1.3.14.3.2.21" | NIST OSE Implementors' Workshop (OIW) Security Digital Signature Algorithm (DSA) coupled with the Secure Hashing Algorithm (SHA). |
| **szOID_OIWSEC_rsaXchg**<br><br>"1.3.14.3.2.22" | NIST OSE Implementors' Workshop (OIW) Security RSA algorithm. |
| **szOID_OIWSEC_keyHashSeal**<br><br>"1.3.14.3.2.23" | NIST OSE Implementors' Workshop (OIW) Security hashing algorithm. |
| **szOID_OIWSEC_md2RSASign**<br><br>"1.3.14.3.2.24" | NIST OSE Implementors' Workshop (OIW) Security RSA algorithm coupled with the Message Digest (MD2) hashing algorithm. |
| **szOID_OIWSEC_md5RSASign**<br><br>"1.3.14.3.2.25" | NIST OSE Implementors' Workshop (OIW) Security RSA algorithm coupled with the Message Digest (MD5) hashing algorithm. |
| **szOID_OIWSEC_sha1**<br><br>"1.3.14.3.2.26" | NIST OSE Implementors' Workshop (OIW) Security Secure Hashing (SHA1) algorithm. |
| **szOID_OIWSEC_dsaSHA1**<br><br>"1.3.14.3.2.27" | NIST OSE Implementors' Workshop (OIW) Security Digital Signature Algorithm (DSA) that uses the Secure Hashing Algorithm 1 (SHA1). |
| **szOID_OIWSEC_dsaCommSHA1**<br><br>"1.3.14.3.2.28" | NIST OSE Implementors' Workshop (OIW) Security Digital Signature Algorithm (DSA) that uses the Secure Hashing Algorithm 1 (SHA1). |
| **szOID_OIWSEC_sha1RSASign**<br><br>"1.3.14.3.2.29" | NIST OSE Implementors' Workshop (OIW) Security RSA algorithm that uses the Secure Hashing Algorithm 1 (SHA1). |
| **szOID_OIWDIR**<br><br>"1.3.14.7.2" | NIST OSE Implementors' Workshop (OIW) Directory root object identifier. |
| **szOID_OIWDIR_CRPT**<br><br>"1.3.14.7.2.1" | NIST OSE Implementors' Workshop (OIW) Directory generic encryption algorithm. |
| **szOID_OIWDIR_HASH**<br><br>"1.3.14.7.2.2" | NIST OSE Implementors' Workshop (OIW) Directory generic hashing algorithm. |
| **szOID_OIWDIR_SIGN**<br><br>"1.3.14.7.2.3" | NIST OSE Implementors' Workshop (OIW) Directory generic signing algorithm. |
| **szOID_OIWDIR_md2**<br><br>"1.3.14.7.2.2.1" | NIST OSE Implementors' Workshop (OIW) Directory Message digest (MD2) algorithm. |
| **szOID_OIWDIR_md2RSA**<br><br>"1.3.14.7.2.3.1" | NIST OSE Implementors' Workshop (OIW) Directory RSA algorithm coupled with the Message digest (MD2) hashing algorithm. |
| **szOID_INFOSEC**<br><br>"2.16.840.1.101.2.1" | INFOSEC object identifier root. |
| **szOID_INFOSEC_sdnsSignature**<br><br>"2.16.840.1.101.2.1.1.1" | Signature algorithm. |
| **szOID_INFOSEC_mosaicSignature**<br><br>"2.16.840.1.101.2.1.1.2" | Signature algorithm. |
| **szOID_INFOSEC_sdnsConfidentiality**<br><br>"2.16.840.1.101.2.1.1.3" | Encryption algorithm. |
| **szOID_INFOSEC_mosaicConfidentiality**<br><br>"2.16.840.1.101.2.1.1.4" | Encryption algorithm. |
| **szOID_INFOSEC_sdnsIntegrity**<br><br>"2.16.840.1.101.2.1.1.5" | Signing algorithm. |
| **szOID_INFOSEC_mosaicIntegrity**<br><br>"2.16.840.1.101.2.1.1.6" | Signing algorithm. |
| **szOID_INFOSEC_sdnsTokenProtection**<br><br>"2.16.840.1.101.2.1.1.7" | Secure Data Network System token encryption. |
| **szOID_INFOSEC_mosaicTokenProtection**<br><br>"2.16.840.1.101.2.1.1.8" | Mosaic token encryption. |
| **szOID_INFOSEC_sdnsKeyManagement**<br><br>"2.16.840.1.101.2.1.1.9" | Secure Data Network System key management. |
| **szOID_INFOSEC_mosaicKeyManagement**<br><br>"2.16.840.1.101.2.1.1.10" | Mosaic key management. |
| **szOID_INFOSEC_sdnsKMandSig**<br><br>"2.16.840.1.101.2.1.1.11" | Secure Data Network System key management and signature. |
| **szOID_INFOSEC_mosaicKMandSig**<br><br>"2.16.840.1.101.2.1.1.12" | Mosaic key management and signature. |
| **szOID_INFOSEC_SuiteASignature**<br><br>"2.16.840.1.101.2.1.1.13" | National Security Agency (NSA) Suite A Cryptography signature algorithm. |
| **szOID_INFOSEC_SuiteAConfidentiality**<br><br>"2.16.840.1.101.2.1.1.14" | National Security Agency (NSA) Suite A Cryptography encryption algorithm. |
| **szOID_INFOSEC_SuiteAIntegrity**<br><br>"2.16.840.1.101.2.1.1.15" | National Security Agency (NSA) Suite A Cryptography signature algorithm. |
| **szOID_INFOSEC_SuiteATokenProtection**<br><br>"2.16.840.1.101.2.1.1.16" | National Security Agency (NSA) Suite A Cryptography security token encryption. |
| **szOID_INFOSEC_SuiteAKeyManagement**<br><br>"2.16.840.1.101.2.1.1.17" | National Security Agency (NSA) Suite A Cryptography security key management. |
| **szOID_INFOSEC_SuiteAKMandSig**<br><br>"2.16.840.1.101.2.1.1.18" | National Security Agency (NSA) Suite A Cryptography key management and signature. |
| **szOID_INFOSEC_mosaicUpdatedSig**<br><br>"2.16.840.1.101.2.1.1.19" | Mosaic updated signature. |
| **szOID_INFOSEC_mosaicKMandUpdSig**<br><br>"2.16.840.1.101.2.1.1.20" | Mosaic key management and updated signature. |
| **szOID_INFOSEC_mosaicUpdatedInteg**<br><br>"2.16.840.1.101.2.1.1.21" | Mosaic updated signature. |
| **szOID_NIST_sha256**<br><br>"2.16.840.1.101.3.4.2.1" | Secure hashing algorithm (SHA) that uses a 256 bit key. |
| **szOID_NIST_sha384**<br><br>"2.16.840.1.101.3.4.2.2" | Secure hashing algorithm (SHA) that uses a 384 bit key. |
| **szOID_NIST_sha512**<br><br>"2.16.840.1.101.3.4.2.3" | Secure hashing algorithm (SHA) that uses a 512 bit key. |
| **szOID_NIST_shake128**<br><br>"2.16.840.1.101.3.4.2.11" | Secure hashing algorithm KECCAK (SHAKE) that uses a 128 bit key. |
| **szOID_NIST_shake256**<br><br>"2.16.840.1.101.3.4.2.12" | Secure hashing algorithm KECCAK (SHAKE) that uses a 256 bit key. |
| **szOID_NIST_ml_dsa_44**<br><br>"2.16.840.1.101.3.4.3.17" | "Pure" Module-Lattice-Based Digital Signature Algorithm (ML-DSA) that uses a 128 bit lattice. |
| **szOID_NIST_ml_dsa_65**<br><br>"2.16.840.1.101.3.4.3.18" | "Pure" Module-Lattice-Based Digital Signature Algorithm (ML-DSA) that uses a 192 bit lattice. |
| **szOID_NIST_ml_dsa_87**<br><br>"2.16.840.1.101.3.4.3.19" | "Pure" Module-Lattice-Based Digital Signature Algorithm (ML-DSA) that uses a 256 bit lattice. |
| **szOID_NIST_hash_ml_dsa_44_with_sha512**<br><br>"2.16.840.1.101.3.4.3.32" | "Pre-Hash" Module-Lattice-Based Digital Signature Algorithm (ML-DSA) that uses a 128 bit lattice. |
| **szOID_NIST_hash_ml_dsa_65_with_sha512**<br><br>"2.16.840.1.101.3.4.3.33" | "Pre-Hash" Module-Lattice-Based Digital Signature Algorithm (ML-DSA) that uses a 192 bit lattice. |
| **szOID_NIST_hash_ml_dsa_87_with_sha512**<br><br>"2.16.840.1.101.3.4.3.34" | "Pre-Hash" Module-Lattice-Based Digital Signature Algorithm (ML-DSA) that uses a 256 bit lattice. |
| **szOID_PKIX_NO_SIGNATURE**<br><br>"1.3.6.1.5.5.7.6.2" | No signature. |
| **szOID_RSA_SSA_PSS**<br><br>"1.2.840.113549.1.1.10" | RSA Signature Scheme with Appendix and Probabilistic Signature Scheme. |
| **szOID_ECDSA_SPECIFIED**<br><br>"1.2.840.10045.4.3" | Elliptic Curve Digital Signature Algorithm (ECDSA). |

### `Parameters`

A [BLOB](https://learn.microsoft.com/windows/win32/SecGloss/b-gly) that provides encoded algorithm-specific parameters. In many cases, there are no parameters. This is indicated by setting the **cbData** member of the **Parameters** BLOB to zero.

The following algorithms have the specified encoded parameters. For more information, see
[Constants for CryptEncodeObject and CryptDecodeObject](https://learn.microsoft.com/windows/win32/SecCrypto/constants-for-cryptencodeobject-and-cryptdecodeobject).

| Value | Meaning |
| --- | --- |
| **szOID_OIWSEC_dsa** | A [CERT_DSS_PARAMETERS](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_dss_parameters) structure. |
| **szOID_RSA_RC2CBC** | A [CRYPT_RC2_CBC_PARAMETERS](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_rc2_cbc_parameters) structure. |
| **szOID_OIWSEC_desCBC** | A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains an [initialization vector](https://learn.microsoft.com/windows/win32/SecGloss/i-gly) in the form of an octet string. |
| **szOID_RSA_DES_EDE3_CBC** | A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains an [initialization vector](https://learn.microsoft.com/windows/win32/SecGloss/i-gly) in the form of an octet string. |
| **szOID_RSA_RC4** | A [CRYPT_DATA_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) that contains an [initialization vector](https://learn.microsoft.com/windows/win32/SecGloss/i-gly) in the form of an octet string. |
| **szOID_RSA_SSA_PSS** | A [CRYPT_RSA_SSA_PSS_PARAMETERS](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_rsa_ssa_pss_parameters) structure. |
| **szOID_ECDSA_SPECIFIED** | A **CRYPT_ALGORITHM_IDENTIFIER** structure. |

## See also

[ALG_ID](https://learn.microsoft.com/windows/win32/SecCrypto/alg-id)

[CERT_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_info)

[CERT_PUBLIC_KEY_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_public_key_info)

[CERT_SIGNED_CONTENT_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cert_signed_content_info)

[CMSG_ENVELOPED_ENCODE_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_enveloped_encode_info)

[CMSG_HASHED_ENCODE_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_hashed_encode_info)

[CMSG_SIGNER_ENCODE_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_signer_encode_info)

[CMSG_SIGNER_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-cmsg_signer_info)

[CRL_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crl_info)

[CRYPT_ENCRYPT_MESSAGE_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_encrypt_message_para)

[CRYPT_HASH_MESSAGE_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_hash_message_para)

[CRYPT_INTEGER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85))

[CRYPT_PRIVATE_KEY_INFO](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_private_key_info)

[CRYPT_SIGN_MESSAGE_PARA](https://learn.microsoft.com/windows/win32/api/wincrypt/ns-wincrypt-crypt_sign_message_para)

[CryptMsgGetParam](https://learn.microsoft.com/windows/win32/api/wincrypt/nf-wincrypt-cryptmsggetparam)