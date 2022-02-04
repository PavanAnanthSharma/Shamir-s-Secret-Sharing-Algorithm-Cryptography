# Shamir-s-Secret-Sharing-Algorithm-Cryptography

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

> Shamir’s Secret Sharing Algorithm: Shamir’s Secret Sharing is an algorithm in cryptography created by Adi Shamir. The main aim of this algorithm is to divide secret that needs to be encrypted into various unique parts. 

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 ## Introduction
 
Cryptography is a technique of securing information and communications through the use of codes so that only those person for whom the information is intended can understand it and process it. Thus preventing unauthorized access to information. The prefix “crypt” means “hidden” and suffix graphy means “writing”. In this article, a type of cryptographic technique, Shamir’s secret sharing algorithm is discussed.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Getting started

- Let’s say S is the secret that we wish to encode.
- It is divided into N parts: S1, S2, S3, …., Sn.
- After dividing it, a number K is chosen by the user in order to decrypt the parts and find the original secret.
- It is chosen in such a way that if we know less than K parts, then we will not be able to find the secret S (i.e.) the secret S can not be reconstructed with (K – 1) parts or fewer.
- If we know K or more parts from S1, S2, S3, …., Sn, then we can compute/reconstructed our secret code S easily. This is conventionally called (K, N) threshold scheme.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
>*Approach: The main idea behind the Shamir’s Secret Sharing Algorithm lies behind the concept that for the given K points we can find a polynomial equation with the degree (K – 1).*

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
