import module2

def my_print(a):
    print('my_print called')

    return 1

var = module2.example(obj={}, number=1, callback=my_print)

print(var)

