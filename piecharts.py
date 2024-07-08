import sys
import matplotlib.pyplot as plt

def create_pie_charts(hit_rates):
    # Titles for the charts based on number of inputs
    titles = ["L1 Cache", "RAM", "L2 Cache", "L3 Cache"]
    
    # Initialize the figure
    fig, axes = plt.subplots(1, len(hit_rates), figsize=(len(hit_rates) * 5, 5))
    
    # If only one subplot, convert axes to a list for consistency
    if len(hit_rates) == 1:
        axes = [axes]
    
    # Generate pie charts
    for i, hit_rate in enumerate(hit_rates):
        labels = ['Hit Rate', 'Miss Rate']
        sizes = [hit_rate, 1 - hit_rate]
        colors = ['blue', 'red']
        
        axes[i].pie(sizes, labels=labels, colors=colors, autopct='%1.1f%%', startangle=140)
        axes[i].axis('equal')  # Equal aspect ratio ensures that pie is drawn as a circle.
        axes[i].set_title(titles[i])
    
    # Display the charts
    plt.tight_layout()
    plt.show()


hit_rates = [float(item) for item in sys.argv[1:]]
create_pie_charts(hit_rates)
