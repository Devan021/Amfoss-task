import hashlib

class RoonCoinBlock:
    
    def __init__(self, previous_block_hash, transaction_list):
        self.previous_block_hash = previous_block_hash
        self.transaction_list = transaction_list
        
        self.block_data = "-".join(transaction_list) + "-" + previous_block_hash
        self.block_hash = hashlib.sha256(self.block_data.encode()).hexdigest()
        
t1 = "Devan made a transaction to Allen"
t2 = "Ashwin made a transaction to Niranjan"
t3 = "Vinayak made a transaction to Uthara"
t4 = "Anjana made a transaction to Smriti"
t5 = "Anjana made a transaction to Allen"
t6 = "Smriti made a transaction to Devan"

initial_block = RoonCoinBlock("Initial String", [t1, t2])

print(initial_block.block_data)
print(initial_block.block_hash) 

second_block = RoonCoinBlock(initial_block.block_hash, [t3, t4])

print(second_block.block_data)
print(second_block.block_hash)

third_block = RoonCoinBlock(second_block.block_hash, [t5, t6])

print(third_block.block_data)
print(third_block.block_hash)
