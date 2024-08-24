import subprocess

def compile_cpp():
    subprocess.run(['g++',  'wavefunction.cpp', 'wavefunction.h', 'main.cpp'], check=True)
    subprocess.run(['./a.exe'], check=True)


def run_python_prog():
    subprocess.run(['python', 'anim.py'], check=True)

def main():
    compile_cpp()
    run_python_prog()

if __name__ == "__main__":
    main()