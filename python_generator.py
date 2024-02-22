import random

def generate_random_sequence(length, min_value, max_value):
    if length > max_value - min_value + 1:
        raise ValueError("La plage de valeurs n'est pas suffisante pour générer une séquence unique")
    return random.sample(range(min_value, max_value + 1), length)

if __name__ == "__main__":
    sequence_length = 100
    min_value = 0
    max_value = 999
    random_sequence = generate_random_sequence(sequence_length, min_value, max_value)
    print(" ".join(map(str, random_sequence)))
