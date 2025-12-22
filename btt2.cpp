import struct

IV = [
    0x6a09e667f3bcc908, 0xbb67ae8584caa73b, 0x3c6ef372fe94f82b, 0xa54ff53a5f1d36f1,
    0x510e527fade682d1, 0x9b05688c2b3e6c1f, 0x1f83d9abfb41bd6b, 0x5be0cd19137e2179
]

def rotr(x, n):
    return ((x >> n) | (x << (64 - n))) & 0xFFFFFFFFFFFFFFFF

def shr(x, n):
    return (x >> n)

def sigma0(x):
    return rotr(x, 1) ^ rotr(x, 8) ^ shr(x, 7)

def sigma1(x):
    return rotr(x, 19) ^ rotr(x, 61) ^ shr(x, 6)

def Ch(e, f, g):
    return (e & f) ^ (~e & g)

def Maj(a, b, c):
    return (a & b) ^ (a & c) ^ (b & c)

def sha512_debug_first_round(message_string):
    message = message_string.encode('utf-8')
    length_bits = len(message) * 8
    
    message += b'\x80'
    
    while (len(message) % 128) != 112:
        message += b'\x00'
        
    message += struct.pack('>Q', 0)
    message += struct.pack('>Q', length_bits)
    
    block = message[:128]
    w = list(struct.unpack('>16Q', block))
    
    w16 = (sigma1(w[14]) + w[9] + sigma0(w[1]) + w[0]) & 0xFFFFFFFFFFFFFFFF
    w.append(w16)
    
    a, b, c, d, e, f, g, h = IV
    
    maj_val = Maj(a, b, c)
    ch_val = Ch(e, f, g)
    
    print(f"Input Message: '{message_string}'")
    print("-" * 40)
    print(f"W[0]  = {w[0]:016x}")
    print(f"W[1]  = {w[1]:016x}")
    print(f"W[15] = {w[15]:016x}")
    print(f"W[16] = {w[16]:016x}")
    print("-" * 40)
    print("Round 0 Values:")
    print(f"Output Majority (Maj)   = {maj_val:016x}")
    print(f"Output Conditional (Ch) = {ch_val:016x}")

sha512_debug_first_round("crypto")
